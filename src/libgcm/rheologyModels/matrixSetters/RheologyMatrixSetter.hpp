#ifndef ISETTER_HPP
#define ISETTER_HPP 

#include "libgcm/util/matrixes.hpp"
#include "libgcm/rheology/Material.hpp"
#include "libgcm/node/CalcNode.hpp"

#include <memory>

namespace gcm
{
    /**
     * Interface to implement for rheology matrix setter. Setter if supposed to modify
     * rheology matrix elements depending on used rheology and plasticity model.
     */
    class RheologyMatrixSetter
    {
        public:
            /**
             * Destructor.
             */
            virtual ~RheologyMatrixSetter() = 0;
            /**
             * Returns number of matrix states after decompositions. This method is supposed to be used to
             * preallocate memory for matrices cache.
             *
             * @return Number of possible states (for one space direction) or 0 if unknown.
             */
            virtual unsigned int getNumberOfStates() const = 0;
            /**
             * Returns number of state for specified node.
             *
             * @param node Node to return state for
             *
             * @return Node state
             */
            virtual unsigned int getStateForNode(const CalcNode& node) const = 0;
            /**
             * Fills matrix \f$A_x\f$ using specified material parameters.
             *
             * @param a Matrix to fill
             * @param material Material to use
             * @param node Node to set matrix at
             */
            virtual void setX(gcm_matrix& a, const MaterialPtr& material, const CalcNode& node) = 0;
            /**
             * Fills matrix \f$A_y\f$ using specified material parameters.
             *
             * @param a Matrix to fill
             * @param material Material to use
             * @param node Node to set matrix at
             */
            virtual void setY(gcm_matrix& a, const MaterialPtr& material, const CalcNode& node) = 0;
            /**
             * Fills matrix \f$A_z\f$ using specified material parameters.
             *
             * @param a Matrix to fill
             * @param material Material to use
             * @param node Node to set matrix at
             */
            virtual void setZ(gcm_matrix& a, const MaterialPtr& material, const CalcNode& node) = 0;

    };

    typedef std::shared_ptr<RheologyMatrixSetter> SetterPtr;
    
    template<typename T, typename...Args>
    std::shared_ptr<T> makeSetterPtr(Args...args)
    {
        return std::make_shared<T>(args...);
    }
}
#endif /* ISETTER_HPP */