#include "../include/header.h"
#include "Eigen/Dense"
#include "Eigen/Core"

float dist(Eigen::VectorXf &v1, Eigen::VectorXf &v2) {
    return (v1 - v2).norm();
}

int main() {
    Eigen::VectorXf v1(2), v2(2);
    v1 << 0, 0;
    v2 << 1, 1;
    std::cout << "Euclidean dist of v1 to v2 is : " << dist(v1, v2) << std::endl;
}