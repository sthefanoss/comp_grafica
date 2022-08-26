//
//  color.hpp
//  computacao_grafica
//
//  Created by Sthefano Schiavon on 26/08/22.
//

#ifndef color_hpp
#define color_hpp

#include <iostream>

struct Color {
  float red;
  float green;
  float blue;
  
  Color(int hex);

  Color(float red = 0, float green = 0, float blue = 0);

  friend std::ostream& operator<<(std::ostream& os, const Color &color);
};

#endif /* color_hpp */
