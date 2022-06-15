#include "../include/header.h"
#include "Eigen/Dense"
#include "Eigen/Core"

float dist(Eigen::VectorXf &v1, Eigen::VectorXf &v2) {
    return (v1 - v2).norm();
}

bool operator<(const Eigen::Vector3d &a, const Eigen::Vector3d &b) {
    return (a.x() < b.x()) && (a.y() < b.y()) && (a.z() < b.z());
}

int main() {
    Eigen::VectorXf v1(2), v2(2);
    v1 << 0, 0;
    v2 << 1, 1;
    cout << "Euclidean dist of v1 to v2 is : " << dist(v1, v2) << endl;
    Eigen::Vector3d a(0, 0, 0);
    Eigen::Vector3d b(1, 1, 1);
    cout << (a < b) << endl;
}


/*
#include <cmath>
#include <iostream>

using namespace std;

template<class Iter_T, class Iter2_T>
double vectorDistance(Iter_T first, Iter_T last, Iter2_T first2) {
    double ret = 0.0;
    while (first != last) {
        double dist = (*first++) - (*first2++);
        ret += dist * dist;
    }
    return ret > 0.0 ? sqrt(ret) : 0.0;
}

int main() {
    int v1[] = { 1, 5 };
    int v2[] = { 4, 9 };
    cout << "distance between vectors (1,5) and (4,9) is ";
    cout << vectorDistance(v1, v1 + 2, v2) << endl;
}*/