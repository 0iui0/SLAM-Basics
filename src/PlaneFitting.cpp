//
// Created by ionic on 2022/6/15.
//
#include "../include/header.h"

using namespace Eigen;

void planeFitting(Matrix<double, Dynamic, 3> const &pts, Vector3d &center, Vector3d &norm) {
    int n = pts.rows();
    for (int i = 0; i < n; ++i) {
        center += pts.row(i);
    }
    center /= n;
    //copy points - average (center)
    Matrix<double, Dynamic, 3> A(n, 3);
    for (int i = 0; i < n; ++i) {
        A(i, 0) = pts(i, 0) - center.x();
        A(i, 1) = pts(i, 1) - center.y();
        A(i, 2) = pts(i, 2) - center.z();
    }
    JacobiSVD<MatrixXd> svd(A, ComputeFullV);
    norm = svd.matrixV().col(2);
}


int main() {
    MatrixXd points = MatrixXd::Random(10, 3);
    Vector3d center;
    Vector3d norm;
    planeFitting(points, center, norm);
    cout << "The least-squares solution is:\n";
    cout << "norm:\t" << norm << endl;
    cout << "center:\t" << center << endl;
}