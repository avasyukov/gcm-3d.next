#include "libgcm/meshes/Mesh.hpp"


using namespace gcm;

Mesh::Mesh() {
	valuesInNodes = NULL;
}

Mesh::~Mesh() {
	if(valuesInNodes != NULL)
		delete[] valuesInNodes;
}

void Mesh::initValuesInNodes(unsigned int numberOfNodes) {
	assert(rheologyModel != NULL);
	CalcNode tmpNode = newNode(rheologyModel->getNodeType());
	uchar sizeOfValuesInODE = tmpNode.getSizeOfValuesInPDE();
	uchar sizeOfValuesInPDE = tmpNode.getSizeOfValuesInODE();
	printf("Mesh: init container for %d variables per node (both PDE and ODE)\n", sizeOfValuesInODE + sizeOfValuesInPDE);
	valuesInNodes = new real[numberOfNodes * (sizeOfValuesInODE + sizeOfValuesInPDE)];
}

CalcNode& Mesh::createNode() {
	unsigned int nodeNum = nodes.size();
	nodes.push_back(newNode(rheologyModel->getNodeType()));
	nodes[nodeNum].initMemory(valuesInNodes, nodeNum);
	return nodes[nodeNum];
}

void Mesh::setRheologyModel(RheologyModel* _rheologyModel) {
	rheologyModel = _rheologyModel;
}

RheologyModel *Mesh::getRheologyModel() {
	return rheologyModel;
}

std::string Mesh::getType() {
	return type;
}