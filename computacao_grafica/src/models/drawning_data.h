//
//  drawning_data.hpp
//  computacao_grafica
//
//  Created by Sthefano Schiavon on 27/08/22.
//

#ifndef drawning_data_hpp
#define drawning_data_hpp

#include <vector>
#include "point.h"
#include "color.h"

struct DrawingData {
  std::vector<std::vector<Point>> paths;
  Color color;
  int type;
  int width;

  DrawingData(){}
    
  DrawingData(const std::vector<std::vector<Point>> &paths, const Color &color, int type, float width = 0);
};

#endif /* drawning_data_hpp */
