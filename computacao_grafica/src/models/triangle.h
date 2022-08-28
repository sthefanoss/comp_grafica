//
//  triangle.hpp
//  computacao_grafica
//
//  Created by Sthefano Schiavon on 27/08/22.
//

#ifndef triangle_hpp
#define triangle_hpp

#include "point.h"

struct Triangle {
    Point a;
    Point b;
    Point c;
    
    Triangle(const Point& a, const Point& b, const Point& c);
};

#endif /* triangle_hpp */
