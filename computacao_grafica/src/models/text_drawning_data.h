//
//  text_drawning_data.hpp
//  computacao_grafica
//
//  Created by Sthefano Schiavon on 27/08/22.
//

#ifndef text_drawning_data_hpp
#define text_drawning_data_hpp

#include <string>
#include "color.h"
#include "point.h"

struct TextDrawingData{
  std::string text;
  Color color;
  Point position;
  void* font;

  TextDrawingData(const std::string &text, const Color &color, const Point &position, void *font);
};

#endif /* text_drawning_data_hpp */
