//
//  triangulation.hpp
//  computacao_grafica
//
//  Created by Sthefano Schiavon on 27/08/22.
//

#ifndef triangulation_hpp
#define triangulation_hpp

#include <vector>
#include "../models/point.h"

class Triangulate {
public:

  // triangulate a contour/polygon, places results in STL vector
  // as series of triangles.
  static bool Process(const std::vector<Point> &contour, std::vector<Point> &result);

  // compute area of a contour/polygon
  static float Area(const std::vector<Point> &contour);

  // decide if point Px/Py is inside triangle defined by
  // (Ax,Ay) (Bx,By) (Cx,Cy)
  static bool InsideTriangle(float Ax, float Ay, float Bx, float By, float Cx, float Cy, float Px, float Py);


private:
  static bool Snip(const std::vector<Point> &contour,int u,int v,int w,int n,int *V);

};


#endif /* triangulation_hpp */
