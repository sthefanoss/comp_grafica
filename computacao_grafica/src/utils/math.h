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

int getFactorial(int number);

int getBinnomialCoefficients(int n, int k);

std::vector<Point> getBezierCurve(int numberOfPoints, std::vector<Point> controlPolygonal);

#endif /* math_hpp */
