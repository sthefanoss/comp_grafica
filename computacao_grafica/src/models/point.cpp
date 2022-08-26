//
//  point.cpp
//  computacao_grafica
//
//  Created by Sthefano Schiavon on 26/08/22.
//

#include "point.h"

Point::Point(float x , float y) {
    this->x = x;
    this->y = y;
}

Point Point::polar(float magnitude, float angle){
    return Point(
      magnitude*cos(angle),
      magnitude*sin(angle)
    );
}

Point Point::rotate(float rotation){
    float sinePart = sin(rotation);
    float cosinePart = cos(rotation);
    
    return Point(
      this->x*cosinePart - this->y*sinePart,
      this->x*sinePart + this->y*cosinePart
    );
}

Point Point::operator+(const Point &other){
    return Point(
      this->x + other.x,
      this->y + other.y
    );
}

Point& Point::operator+=(const Point &other){
    this->x += other.x;
    this->y += other.y;
    return *this;
}

Point Point::operator*(float scalar){
    return Point(
      this->x*scalar,
      this->y*scalar
    );
}

std::ostream& operator<<(std::ostream& os,const Point &point) {
    os << "Point("<< point.x << ", " << point.y << ")";
    return os;
}
