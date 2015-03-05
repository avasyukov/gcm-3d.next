#ifndef CUBICMESH_HPP
#define	CUBICMESH_HPP

#include "libgcm/meshes/Mesh.hpp"

namespace gcm {
	class CubicMesh : public Mesh {
	public:
		CubicMesh();
		CubicMesh(const CubicMesh& orig);
		~CubicMesh();
		void load(std::vector<CalcNode>& vertices, unsigned char indx) override;
		void checkTopology(float tau) override;

	private:

	};
}

#endif	/* CUBICMESH_HPP */
