//
//  point.hpp
//  computacao_grafica
//
//  Created by Sthefano Schiavon on 26/08/22.
//

#ifndef point_hpp
#define point_hpp

#include <iostream>
#include <cmath>

#endif /* point_hpp */

struct Point {
    float x;
    float y;

    Point(float x = 0, float y = 0);

    static Point polar(float magnitude, float angle);

    Point rotate(float rotation);

    Point operator+(const Point &other);

    Point& operator+=(const Point &other);

    Point operator*(float scalar);
    
   friend std::ostream& operator<<(std::ostream& os, const Point &point);
};
