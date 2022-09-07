//
//  math.hpp
//  computacao_grafica
//
//  Created by Sthefano Schiavon on 27/08/22.
//

#ifndef math_hpp
#define math_hpp

#include <vector>
#include "../models/point.h"

std::vector<Point> getCirclePolygon(const Point& center, float radius, unsigned segments = 100);

#endif /* math_hpp */
