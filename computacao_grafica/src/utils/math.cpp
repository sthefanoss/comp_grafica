//
//  math.cpp
//  computacao_grafica
//
//  Created by Sthefano Schiavon on 27/08/22.
//

#include "math.h"

std::vector<Point> getCirclePolygon(const Point& center, float radius, unsigned segments) {
    std::vector<Point> result = {};
    float dtetha = 2 * M_PI / segments;
    
    for(unsigned i=0; i<segments; i++){
        float tetha = dtetha * i;
        Point point = Point(
          center.x + radius * cos(tetha),
          center.y + radius * sin(tetha)
        );
        
        result.push_back(point);
    }
    
    return result;
}
