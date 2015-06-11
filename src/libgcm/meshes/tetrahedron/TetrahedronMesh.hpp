#ifndef TETRAHEDRONMESH_HPP
#define	TETRAHEDRONMESH_HPP

#include "libgcm/meshes/Mesh.hpp"

namespace gcm {
	class TetrahedronMesh : public Mesh {
	public:
		TetrahedronMesh();
		TetrahedronMesh(const TetrahedronMesh& orig);
		~TetrahedronMesh();
		void checkTopology(float tau) override;
	private:

	};
}

#endif	/* TETRAHEDRONMESH_HPP */
