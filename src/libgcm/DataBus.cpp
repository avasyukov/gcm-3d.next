#include "libgcm/DataBus.hpp"

using namespace gcm;
using namespace MPI;
using std::vector;
using std::cout;
using std::endl;

#define BARRIER(name) \
do { \
    LOG_DEBUG("Entering barrier: " << name); \
    COMM_WORLD.Barrier(); \
    LOG_DEBUG("Barrier passed: " << name); \
} while(0)

DataBus::DataBus()
{
	rank = COMM_WORLD.Get_rank();
	numberOfWorkers = COMM_WORLD.Get_size();

	createStaticTypes();
}

DataBus::~DataBus()
{

}

void DataBus::createStaticTypes()
{
	CalcNode* empty_node = new CalcNode [2];
	TetrahedronFirstOrder* tetr = new TetrahedronFirstOrder [2];
	Cube* cube = new Cube [2];

	// Empty node
	Datatype empty_node_types[] = {
		LB,
		FLOAT,
		UNSIGNED,
		UB
	};

	int empty_node_lengths [] = { 1, 3, 1, 1};

	Aint empty_node_disp[] = {
			Get_address(&empty_node[0]),
			Get_address(&empty_node[0].coords[0]),
			Get_address(&empty_node[0].number),
			Get_address(&empty_node[1])
	};

	for(int i = 3; i >= 0; i--)
		empty_node_disp[i] -= Get_address(&empty_node[0]);

	MPI_EMPTY_NODE = Datatype::Create_struct(4, empty_node_lengths, empty_node_disp, empty_node_types);

	// Tetrahedron
	Datatype tetr_types[] = {
		LB,
		UNSIGNED,
		UNSIGNED,
		UB
	};

	int tetr_lengths [] = { 1, 4, 1, 1};

	Aint tetr_disp[] = {
			Get_address(&tetr[0]),
			Get_address(&tetr[0].vertices[0]),
			Get_address(&tetr[0].number),
			Get_address(&tetr[1])
	};

	for(int i = 3; i >= 0; i--)
		tetr_disp[i] -= Get_address(&tetr[0]);

	MPI_TETR = Datatype::Create_struct(4, tetr_lengths, tetr_disp, tetr_types);

	// Cube
	Datatype cube_types[] = {
		LB,
		UNSIGNED,
		UNSIGNED,
		UB
	};

	int cube_lengths [] = { 1, 8, 1, 1};

	Aint cube_disp[] = {
			Get_address(&cube[0]),
			Get_address(&cube[0].vertices[0]),
			Get_address(&cube[0].number),
			Get_address(&cube[1])
	};

	for(int i = 3; i >= 0; i--)
		cube_disp[i] -= Get_address(&cube[0]);

	MPI_CUBE = Datatype::Create_struct(4, cube_lengths, cube_disp, cube_types);

	MPI_EMPTY_NODE.Commit();
	MPI_TETR.Commit();
	MPI_CUBE.Commit();

}

void DataBus::transferMesh(TetrMeshFirstOrder* mesh)
{

	BARRIER("DataBus: starting coarse meshes delivery!");

	if(rank == 0) {

		for(uint i = 1; i < numberOfWorkers; i++)
		{
			// Sending nodes
			MPI_Send(&mesh[i].nodes[0], mesh[i].nodes.size(), MPI_EMPTY_NODE, i, TAG_EMPTY_NODES + i, MPI_COMM_WORLD);

			std::cout << "Core#" << rank << ": " << mesh[i].nodes.size() << " nodes sent to Core#" << i << endl;

			// Sending tetrahedrons
			MPI_Send(&mesh[i].tetrs1[0], mesh[i].tetrs1.size(), MPI_TETR, i, TAG_TETRS + i, MPI_COMM_WORLD);

			std::cout << "Core#" << rank << ": " << mesh[i].tetrs1.size() << " tetrahedrons sent to Core#" << i << endl;
		}

	} else {
		int size;
		MPI_Status status;

		vector<CalcNode> nodes;
		vector<TetrahedronFirstOrder> tetrs;
    
		// Receiving nodes
		MPI_Probe(0, TAG_EMPTY_NODES + rank, MPI_COMM_WORLD, &status);
		MPI_Get_count(&status, MPI_EMPTY_NODE, &size);
		nodes.resize(size);
		MPI_Recv(&nodes[0], size, MPI_EMPTY_NODE, 0, TAG_EMPTY_NODES + rank, MPI_COMM_WORLD, &status);

		mesh->initNodesWithoutValues(size);
		for(int i = 0; i < size; i++)
			mesh->addNode(nodes[i]);

		std::cout << "Core#" << rank << ": " << size << " nodes received from Core#" << 0 << endl;

		// Receiving tetrahedrons
		MPI_Probe(0, TAG_TETRS + rank, MPI_COMM_WORLD, &status);
		MPI_Get_count(&status, MPI_TETR, &size);
		tetrs.resize(size);
		MPI_Recv(&tetrs[0], size, MPI_TETR, 0, TAG_TETRS + rank, MPI_COMM_WORLD, &status);
		
		mesh->createTetrs(size);
		for(int i = 0; i < size; i++)
			mesh->addTetr(tetrs[i]);

		std::cout << "Core#" << rank << ": " << size << " tetrahedrons received from Core#" << 0 << endl;
	}

	BARRIER("DataBus: coarse meshes transfered!");

}
