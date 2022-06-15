//
// Created by ionic on 2022/6/15.
//
#include "../include/header.h"

using namespace Eigen;

void planeFitting(Eigen::Matrix<float, Eigen::Dynamic, 3> const &pts, Eigen::Vector3f &center, Eigen::Vector3f &norm) {
    int n = pts.rows();
    for (int i = 0; i < n; ++i) {
        center += pts.row(i);
    }
    center /= n;
    //copy points - average (center)
    Eigen::Matrix<float, Eigen::Dynamic, 3> A(n, 3);
    for (int i = 0; i < n; ++i) {
        A(i, 0) = pts(i, 0) - center.x();
        A(i, 1) = pts(i, 1) - center.y();
        A(i, 2) = pts(i, 2) - center.z();
    }
    Eigen::JacobiSVD<Eigen::MatrixXf> svd(A, Eigen::ComputeFullV);
    norm = svd.matrixV().col(2);
}


int main() {
    MatrixXf A = MatrixXf::Random(10, 3);
    VectorXf b = VectorXf::Random(10);
    cout << "Here is the matrix A:\n" << A << endl;
    cout << "Here is the right hand side b:\n" << b << endl;
    Eigen::Vector3f center;
    Eigen::Vector3f norm;
    planeFitting(A, center, norm);
    cout << "The least-squares solution is:\n";
    cout << "norm:\t" << norm << endl;
    cout << "center:\t" << center << endl;

    cout << "The solution using normal equations is:\n"
         << (A.transpose() * A).ldlt().solve(A.transpose() * b) << endl;
}