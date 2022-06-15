#include "../include/header.h"

using namespace Eigen;

// A hash function used to hash a pair of any kind
struct hash_pair {
    template<class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

/// Grid position, Grid landmark, hash
template<class T1, class T2, class T3>
struct GridMap {
    typedef unordered_map<pair<T1, T2>, T3, hash_pair> gridMap_t;

};

int main() {
    GridMap<double, double, double>::gridMap_t gridMap;
    return 0;
}