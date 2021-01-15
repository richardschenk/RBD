#ifndef _GROUND_HDD_
#define _GROUND_HDD_
#include <vector>
#include "..\headers\Vector.hpp"
class Ground {
    private:
        std::vector<Vector> edges;
    public:
        void addEdge(float, float);
};
#endif