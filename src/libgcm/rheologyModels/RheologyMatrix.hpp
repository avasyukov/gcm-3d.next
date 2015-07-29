#ifndef _GCM_RHEOLOGY_MATRIX__H
#define _GCM_RHEOLOGY_MATRIX__H  1

#include <memory>
#include <vector>

#include "libgcm/rheologyModels/GcmMatrix.hpp"
#include "libgcm/rheologyModels/Material.hpp"
#include "libgcm/rheologyModels/matrixSetters/RheologyMatrixSetter.hpp"
#include "libgcm/solvers/matrixDecomposers/RheologyMatrixDecomposer.hpp"

namespace gcm
{
    class CalcNode;

    /**
     * Holds rheology matrix A and provides a way to compute «decomposition» of
     * original matrix to 3 matrices \f$U\f$, \f$\Lambda\f$, \f$U^{-1}\f$
     * that  \f$U^{-1} * \Lambda * U == A\f$.
     */

    class RheologyMatrix
    {
    private:
        /**
         * Size of matrices. Actually, it's number of variables in PDE. So, depends on model.
         */
        uchar size;
        /**
         * Material this matrix was created for.
         */
        MaterialPtr material;
        /**
         * Matrix setter to use.
         */
        SetterPtr setter;
        /**
         * Matrix decomposer to use.
         */
        DecomposerPtr decomposer;
        /**
         * Matrices cache.
         */
        // We use vectors since we need non-default constructors for matrices (pass size correctly)
        // There is no reasonable option to do it for arrays even with C++11 (ugly, yeh).
        // See RheologyMatrix constructor implementation for details
        struct
        {
            std::vector<GcmMatrix> a;
            std::vector<GcmMatrix> u;
            std::vector<GcmMatrix> l;
            std::vector<GcmMatrix> u1;
            std::vector<bool> cached;
        } matrices[3];
        /**
         * Immutable flag.
         */
        bool immutable = true;
        /**
         * Index of current matrix in cache.
         */
        int index = 0;
        /**
         * Current direction number.
         */
        unsigned int direction = 0;
    public:
        /**
         * Constructs new rheology matrix.
         *
         * @param size Number of variables in PDE in current model
         * @param material Material to use for this matrix
         * @param setter Rheology matrix setter
         * @param decomposer Rheology matrix decomposer
         */
        RheologyMatrix(uchar size, const MaterialPtr& material, const SetterPtr& setter, const DecomposerPtr& decomposer);
        /**
         * Disabled copy constructor.
         */
        RheologyMatrix(const RheologyMatrix& that);
        /**
         * Destructor
         */
        ~RheologyMatrix();
        /**
         * Returns matrix size (equals to number of variables in PDE).
         * @return matrix size.
         */
        uchar getSize() const;
        /**
         * Returns max matrix eigenvalue.
         * @return max eigenvalue.
         */
        real getMaxEigenvalue() const;
        /**
         * Returns min matrix eigenvalue.
         * @return min eigenvalue.
         */
        real getMinEigenvalue() const;
        /**
         * Returns rheology matrix A.
         * @return A matrix.
         */
        const GcmMatrix& getA() const;
        /**
         * Returns rheology matrix A component.
         * @return A matrix component.
         */
        real getA(unsigned int i, unsigned int j) const;
        /**
         * Returns \f$\Lambda\f$ matrix (contains eigenvalues).
         * @return \f$\Lambda\f$ matrix.
         */
        const GcmMatrix& getL() const;
        /**
         * Returns \f$\Lambda\f$ matrix component.
         * @return \f$\Lambda\f$ matrix component.
         */
        real getL(unsigned int i, unsigned int j) const;
        /**
         * Returns U matrix (contains eigenstd::vectors).
         * @return U matrix.
         */
        const GcmMatrix& getU() const;
        /**
         * Returns U matrix component.
         * @return U matrix component.
         */
        real getU(unsigned int i, unsigned int j) const;
        /**
         * Returns \f$U^{-1}\f$ matrix (inverse U).
         * @return \f$U^{-1}\f$ matrix.
         */
        const GcmMatrix& getU1() const;
        /**
         * Returns \f$U^{-1}\f$ matrix component.
         * @return \f$U^{-1}\f$ matrix component.
         */
        real getU1(unsigned int i, unsigned int j) const;
        /**
         * Returns material.
         *
         * @return material
         */
        const MaterialPtr& getMaterial() const;      
        /**
         * Computes rheology matrix decomposition (\f$A_x\f$).
         *
         * @param node Node to compute decomposition in.
         */
        void decomposeX(const CalcNode& node);
        /**
         * Computes rheology matrix decomposition (\f$A_y\f$).
         *
         * @param node Node to compute decomposition in.
         */
        void decomposeY(const CalcNode& node);
        /**
         * Computes rheology matrix decomposition (\f$A_z\f$).
         *
         * @param node Node to compute decomposition in.
         */
        void decomposeZ(const CalcNode& node);
        /**
         * Computes rheology matrix decomposition for specified direction.
         *
         * @param node Node to compute decomposition in
         * @param direction Direction to compute decomposition for
         */
        void decompose(const CalcNode& node, unsigned int direction);
        
    };

    typedef std::shared_ptr<RheologyMatrix> RheologyMatrixPtr;

    template<typename...Args>
    RheologyMatrixPtr makeRheologyMatrixPtr(Args...args)
    {
        return std::make_shared<RheologyMatrix>(args...);
    }

    template<typename SetterType, typename DecomposerType>
    RheologyMatrixPtr  makeRheologyMatrixPtr(MaterialPtr material)
    {
        return makeRheologyMatrixPtr(material, makeSetterPtr<SetterType>(), makeDecomposerPtr<DecomposerType>());
    }
}

#endif