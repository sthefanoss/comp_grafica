#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <functional>

#include "models/point.h"
#include "models/color.h"
#include "models/drawning_data.h"
#include "models/text_drawning_data.h"
#include "utils/functional.h"
#include "utils/triangulate.h"
#include "utils/math.h"

#define XD_MAX 800
#define YD_MAX 800
#define IMAGE_OFFSET 100
#define IMAGE_SCALE 10

std::vector<Point> outterPolygonal = {
    Point(0,0),
    Point(10,0),
    Point(10,5),
    Point(30,10),
    Point(50,10),
    Point(50,30),
    Point(45,30),
    Point(45,60),
    Point(15,60),
    Point(15,40),
    Point(5,30),
    Point(5,25),
    Point(0,25),
};

std::vector<Point> rectanglePolygonal = {
    Point(20,40),
    Point(40,40),
    Point(40,55),
    Point(20,55),
};

void drawFilledPolygonal(const std::vector<Point>& polygon,const Color& color) {
    std::vector<Point> trianglePoints = {};
    Triangulate().Process(polygon, trianglePoints);
    
    glBegin(GL_TRIANGLES);
    glColor3f(color.red, color.green, color.blue);
    for (Point point : trianglePoints) {
      glVertex2f(IMAGE_OFFSET + point.x * IMAGE_SCALE, IMAGE_OFFSET + point.y * IMAGE_SCALE);
    }
    glEnd();
}

void drawWindow() {
    Point circlesCenter = Point(30,40);
    std::vector<Point> greaterCirclePolygonal = getCirclePolygon(circlesCenter, 10.0f);
    std::vector<Point> smallerCirclePolygonal = getCirclePolygon(circlesCenter, 5.0f);
  
    
    
  glClear(GL_COLOR_BUFFER_BIT);
    drawFilledPolygonal(outterPolygonal, Color(1,1,0));
    drawFilledPolygonal(rectanglePolygonal, Color(0,1,0));
    drawFilledPolygonal(greaterCirclePolygonal, Color(1,0,0));
    drawFilledPolygonal(smallerCirclePolygonal, Color(0,1,0));
        
  glutSwapBuffers();
}

void onChangeWindowSize(GLsizei width, GLsizei height) {
  if (height == 0)
    height = 1;

  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (width <= height)
    gluOrtho2D(0, XD_MAX, 0, YD_MAX * height / width);
  else
    gluOrtho2D(0, XD_MAX * width / height, 0, YD_MAX);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(XD_MAX, YD_MAX);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("OpenGL - Anima Aviao-STHEFANO SCHIAVON");
  glutDisplayFunc(drawWindow);
  glutReshapeFunc(onChangeWindowSize);
  setbuf(stdin,NULL);
  glutMainLoop();
  return 0;
}
