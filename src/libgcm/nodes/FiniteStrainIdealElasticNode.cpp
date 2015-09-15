#include "libgcm/nodes/FiniteStrainIdealElasticNode.hpp"
#include "libgcm/util/Assertion.hpp"
#include "libgcm/util/Math.hpp"

using namespace gcm;

FiniteStrainIdealElasticNode::FiniteStrainIdealElasticNode() : 
		IdealElasticNode(10, 0, gcm::FINITE_STRAIN_IDEAL_ELASTIC_NODE_TYPE)
{
}

// Read-only get-ters
real FiniteStrainIdealElasticNode::getRho() const {
    return PDE[9];
}

// Read-write access
real& FiniteStrainIdealElasticNode::rho() {
    return PDE[9];
}