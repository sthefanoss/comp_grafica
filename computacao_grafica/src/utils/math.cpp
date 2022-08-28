//
//  math.cpp
//  computacao_grafica
//
//  Created by Sthefano Schiavon on 27/08/22.
//

#include "math.h"

int getFactorial(int number) {
  return number == 0 ? 1 : number * getFactorial(number - 1);
}

int getBinnomialCoefficients(int n, int k) {
  int numerator =  getFactorial(n);
  int denominator = getFactorial(k)*getFactorial(n-k);
  return numerator/denominator;
}

std::vector<Point> getBezierCurve(int numberOfPoints, std::vector<Point> controlPolygonal) {
  std::vector<Point> result = {};
  float dt = 1.0/(numberOfPoints-1.0);
  int n = controlPolygonal.size() - 1;

  for(float t = 0; t <= 1; t += dt) {
    Point pointOfT = Point();

    for(int i = 0; i <= n; i++)
      pointOfT += controlPolygonal[i] * getBinnomialCoefficients(n, i) * pow(t, i)*pow(1-t,n-i);
    
    result.push_back(pointOfT);
  }

  return result;
}
