//
//  text_drawning_data.cpp
//  computacao_grafica
//
//  Created by Sthefano Schiavon on 27/08/22.
//

#include "text_drawning_data.h"

TextDrawingData::TextDrawingData(const std::string &text, const Color &color, const Point &position, void *font) {
    this->text = text;
    this->color = color;
    this->position = position;
    this->font = font;
}

