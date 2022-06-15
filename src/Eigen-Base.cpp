//
// Created by ionic on 2022/6/14.
//

// src/Core/MatrixBase.h
//    template<typename Derived>
//    class MatrixBase
//    {
//        // ...
//
//        template<typename OtherDerived>
//        const CwiseBinaryOp<internal::scalar_sum_op<typename internal::traits<Derived>::Scalar>, Derived, OtherDerived>
//        operator+(const MatrixBase<OtherDerived> &other) const;
//
//        // ...
//    };

// src/Core/Assign.h       assign_selector
//    template<typename Derived>
//    template<typename OtherDerived>
//    inline Derived& MatrixBase<Derived>
//    ::operator=(const MatrixBase<OtherDerived>& other)
//    {
//        return internal::assign_selector<Derived,OtherDerived>::run(derived(), other.derived());
//    }

#include "../include/header.h"
#include "Eigen/Dense"
#include "Eigen/Core"

// What happens inside Eigen, on a simple example
int main() {
    int size = 3;
    // src/Core/Matrix.h
    //    typedef Matrix<float, Dynamic, 1> VectorXf;
    // src/Core/DenseStorage.h
    //    template<typename T, int Cols_> class DenseStorage<T, Dynamic, Dynamic, Cols_>
    // src/Core/util/Memory.h  aligned_new
    //    inline DenseStorage(int size, int rows, int) : m_data(internal::aligned_new<T>(size)), m_rows(rows) {}
    //    What it does is that:
    //    if vectorization is enabled, then it uses a platform-specific call to allocate a 128-bit-aligned array,
    //    as that is very useful for vectorization with both SSE2 and AltiVec.
    //    If vectorization is disabled, it amounts to the standard new[].

    Eigen::VectorXf u(size), v(size), w(size);

    // VectorXf is a vector of floats, with dynamic size.
    // TODO what Eigen has done!!!!!   https://eigen.tuxfamily.org/dox/TopicInsideEigenExample.html
    //    class MatrixBase<VectorXf>
    //    {
    //        // ...
    //
    //        const CwiseBinaryOp<internal::scalar_sum_op<float>, VectorXf, VectorXf>
    //        operator+(const MatrixBase<VectorXf> &other) const;
    //
    //        // ...
    //    };
    u = v + w;
    //    v+w
    //    Thus, the operator+ hasn't performed any actual computation.
    //    To summarize, the operation v + w just returned an object of type CwiseBinaryOp which did nothing else than
    //    just storing references to v and w.

    //    u=
    //    The operator= literally reads "copying a sum of two VectorXf's into another VectorXf".
    cout << u << endl;
    //    conclusion
    //    Eigen behaves like a script for the compiler.
    //    In a sense, C++ template metaprogramming is scripting the compiler –
    //    and it's been shown that this scripting language is Turing-complete.
}