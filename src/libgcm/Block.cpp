#include "Block.hpp"

using namespace gcm;

Block::Block(const BlockProperties& prop) {
	Engine& engine = Engine::getInstance();
	model = engine.getRheologyModel(prop.modelType);
	solver = engine.getSolver(prop.solverType);

	if (prop.meshType == "CubicMesh") {
		CubicMesh *mesh = new CubicMesh();
		mesh->setId("testMesh");
		mesh->setRheologyModel(model);

		CubicMeshLoader::getInstance().loadMesh(mesh, prop.geometry, prop.spatialStep);
		meshes.push_back(mesh);
	} else if (prop.meshType == "TetrahedronMesh") {
		TetrMeshFirstOrder* mesh = new TetrMeshFirstOrder();
		mesh->setId("testMesh");
		mesh->setRheologyModel(model);

		TetrahedronMeshLoader::getInstance().loadMesh(mesh, "models/cube.geo", prop.spatialStep);
		meshes.push_back(mesh);
	}
}

void Block::doNextTimeStep()
{
	for(auto mesh = meshes.begin(); mesh != meshes.end(); mesh++) {
		solver->doNextTimeStep(*mesh);
		(*mesh)->snapshot(1);
	}
}

void Block::checkTopology(real tau)
{
	for(auto mesh = meshes.begin(); mesh != meshes.end(); mesh++)
		(*mesh)->checkTopology(tau);
}
