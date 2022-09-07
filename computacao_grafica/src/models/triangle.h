//
//  triangle.hpp
//  computacao_grafica
//
//  Created by Sthefano Schiavon on 27/08/22.
//

#ifndef triangle_hpp
#define triangle_hpp

#include <functional>
#include "point.h"

struct Triangle {
    Point a;
    Point b;
    Point c;
    
    Triangle(const Point& a, const Point& b, const Point& c);

    void forEachPoint(std::function<void(Point)> callback);
};

#endif /* triangle_hpp */
