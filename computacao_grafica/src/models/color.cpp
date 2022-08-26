//
//  color.cpp
//  computacao_grafica
//
//  Created by Sthefano Schiavon on 26/08/22.
//

#include "color.h"

Color::Color(int hex) {
    this->blue = ((hex & 0x0000FF))/255.0;
    this->green = ((hex & 0x00FF00) >> 8)/255.0;
    this->red = ((hex & 0xFF0000) >> 16)/255.0;
}

Color::Color(float red, float green, float blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}

std::ostream& operator<<(std::ostream& os, const Color &color) {
    os << "Color(red:"<< color.red << ", green:" << color.green << ", blue:" << color.blue<<")";
    return os;
}
