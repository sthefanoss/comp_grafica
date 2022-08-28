//
//  drawning_data.cpp
//  computacao_grafica
//
//  Created by Sthefano Schiavon on 27/08/22.
//

#include "drawning_data.h"
#include "../utils/functional.h"

DrawingData::DrawingData(const std::vector<std::vector<Point>> &paths, const Color &color, int type, float width) {
    this->paths = paths;
    this->color = color;
    this->type = type;
    this->width = width;
}

DrawingData DrawingData::transform(std::function<Point(const Point&)> callback) {
    std::vector<std::vector<Point>> transformedPaths =
      map<std::vector<Point>>(this->paths, [&](std::vector<Point> path) {
       return map<Point>(path, callback);
          
      }
    );

    return DrawingData(
      transformedPaths,
      this->color,
      this->type,
      this->width
    );
}

DrawingData DrawingData::translate(Point offset) {
    return this->transform([&](Point point){
        return point + offset;
      }
    );
}

DrawingData DrawingData::rotate(float angle) {
    return this->transform([&](Point point){
        return point.rotate(angle);
    }
    );
}

