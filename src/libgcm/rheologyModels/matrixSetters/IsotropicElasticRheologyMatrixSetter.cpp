#include "libgcm/rheologyModels/matrixSetters/IsotropicElasticRheologyMatrixSetter.hpp"

using namespace gcm;
unsigned int IsotropicElasticRheologyMatrixSetter::getNumberOfStates() const
{
    return 1;
}

unsigned int IsotropicElasticRheologyMatrixSetter::getStateForNode(const CalcNode& node) const
{
    return 0;
}

void IsotropicElasticRheologyMatrixSetter::setX(GcmMatrix& a, const MaterialPtr& material, const CalcNode& node)
{
    a.clear();
    
    auto rho = material->getRho();
    auto mu = material->getMu();
    auto la = material->getLa();

    a(0, 3) = -1 / rho;
    a(1, 4) = -1 / rho;
    a(2, 5) = -1 / rho;
    a(3, 0) = -la - 2 * mu;
    a(4, 1) = -mu;
    a(5, 2) = -mu;
    a(6, 0) = -la;
    a(8, 0) = -la;
}

void IsotropicElasticRheologyMatrixSetter::setY(GcmMatrix& a, const MaterialPtr& material, const CalcNode& node)
{
    a.clear();
    
    auto rho = material->getRho();
    auto mu = material->getMu();
    auto la = material->getLa();
    
    a(0, 4) = -1 / rho;
    a(1, 6) = -1 / rho;
    a(2, 7) = -1 / rho;
    a(3, 1) = -la;
    a(4, 0) = -mu;
    a(6, 1) = -la - 2 * mu;
    a(7, 2) = -mu;
    a(8, 1) = -la;
}

void IsotropicElasticRheologyMatrixSetter::setZ(GcmMatrix& a, const MaterialPtr& material, const CalcNode& node)
{
    a.clear();
    
    auto rho = material->getRho();
    auto mu = material->getMu();
    auto la = material->getLa();
    
    a(0, 5) = -1 / rho;
    a(1, 7) = -1 / rho;
    a(2, 8) = -1 / rho;
    a(3, 2) = -la;
    a(5, 0) = -mu;
    a(6, 2) = -la;
    a(7, 1) = -mu;
    a(8, 2) = -la - 2 * mu;
}