#include <iostream>

#include "headers\Ground.hpp"
#include "headers\Vector.hpp"
using namespace std;

int main() {
    Vector v = Vector(3.6, 5.2);
    cout << v.getY() << endl;
}