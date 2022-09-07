//
//  drawning_data.cpp
//  computacao_grafica
//
//  Created by Sthefano Schiavon on 27/08/22.
//

#include "drawning_data.h"

DrawingData::DrawingData(const std::vector<std::vector<Point>> &paths, const Color &color, int type, float width) {
    this->paths = paths;
    this->color = color;
    this->type = type;
    this->width = width;
}