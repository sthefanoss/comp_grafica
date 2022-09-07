//
//  triangle.cpp
//  computacao_grafica
//
//  Created by Sthefano Schiavon on 27/08/22.
//

#include "triangle.h"

Triangle::Triangle(const Point& a, const Point& b, const Point& c) {
    this->a = a;
    this->b = b;
    this->c = c;
}

void Triangle::forEachPoint(std::function<void(Point)> callback) {
    callback(a);
    callback(b);
    callback(c);
}