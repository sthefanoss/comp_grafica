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

#define XD_MAX 800
#define YD_MAX 600

std::vector<DrawingData> g_staticDrawings;
std::vector<TextDrawingData> g_texts;
DrawingData g_planeDrawing;
Point g_planeOffset;
float g_planeRotation;
float g_planeVelocity;

int getFactorial(int number) {
  return number == 0 ? 1 : number * getFactorial(number - 1);
}

int getBinnomialCoefficients(int n, int k) {
  int numerator =  getFactorial(n);
  int denominator = getFactorial(k)*getFactorial(n-k);
  return numerator/denominator;
}

std::vector<Point> getBezierCurve(int numberOfPoints, std::vector<Point> controlPolygonal) {
  std::vector<Point> result = {};
  float dt = 1.0/(numberOfPoints-1.0);
  int n = controlPolygonal.size()-1;

  for(float t = 0; t <= 1; t += dt) {
    Point pointOfT = Point();

    for(int i = 0; i <= n; i++)
      pointOfT += controlPolygonal[i] * getBinnomialCoefficients(n, i) * pow(t, i)*pow(1-t,n-i);
    
    result.push_back(pointOfT);
  }

  return result;
}

void onSpecialInput(int key, int x, int y) {
  switch(key){
    case 100:
      if(!g_planeVelocity)
        return;

      g_planeRotation -= 0.2*(1 - 0.5*g_planeVelocity/3);
      break;

    case 102:
      if(!g_planeVelocity)
        return;

      g_planeRotation += 0.2*(1 - 0.5*g_planeVelocity/3);
      break;

    case 101:
      if(g_planeVelocity>3)
        break;

      g_planeVelocity += 1;
      break;

    case 103:
      g_planeVelocity -= 1.5;
      if(g_planeVelocity<0)
        g_planeVelocity = 0;
      break;

    default:
      break;
  }
}


void updateFrame(int dt){
  g_planeOffset += Point::polar(g_planeVelocity, g_planeRotation);

  glutPostRedisplay();

  glutTimerFunc(dt,updateFrame,dt);
}

void init () {
  Color lightGray = Color(0x7F7F7F);
  Color gray = Color(0x808080);
  Color black = Color(0x000000);

  DrawingData airportTerminal = DrawingData(
    {
      {
        Point(270,545),
        Point(270,268),
        Point(411,268),
        Point(411,388),
        Point(731,388),
        Point(731,545),
      }
    },
    black,
    GL_LINE_LOOP,
    3
  );
 
 DrawingData terminalGate = DrawingData(
    {
      {
        Point(620,388),
        Point(620,335),
        Point(607,335),
        Point(607,326),
        Point(629,326),
        Point(629,388),
      }
    },
    lightGray,
    GL_LINE_LOOP,
    2
  );

  g_planeOffset = Point(137,449);
  g_planeRotation = -M_PI/2;
  g_planeVelocity = 0;
  g_planeDrawing = DrawingData(
    {
      {
        Point(0, 87),
        Point(7, 71),
        Point(7, -49),
        Point(0, -65),
        Point(-7, -49),
        Point(-7, 71),
      },{
        Point(-97, 26),
        Point(-7, 14),
        Point(-7, -15),
        Point(-97, 16),
      },{
        Point(97, 26),
        Point(7, 14),
        Point(7, -15),
        Point(97, 16),
      }
    },
    gray,
    GL_POLYGON,
    1
  );

  g_staticDrawings = {
    terminalGate,
    airportTerminal,
  };

  TextDrawingData airportTerminalText = TextDrawingData(
    "TERMINAL DE PASSAGEIROS",
    black,
    Point(312,465),
    GLUT_BITMAP_HELVETICA_18
  );

  TextDrawingData terminalGateText = TextDrawingData(
    "GATE 01",
    black,
    Point(637,346),
    GLUT_BITMAP_HELVETICA_12
  );

  g_texts = {
    airportTerminalText,
    terminalGateText
  };

  glClearColor(1, 1, 1, 0);
}

void drawText(const TextDrawingData& data){
  glColor3f(data.color.red, data.color.green, data.color.blue);
  glRasterPos2i((int) data.position.x, YD_MAX - (int) data.position.y);
  for(char character : data.text)
    glutBitmapCharacter(data.font, character);
}

void drawPaths (const DrawingData& data) {
  for(std::vector<Point> path : data.paths) {
    glColor3f(data.color.red, data.color.green, data.color.blue);
    if(data.width > 0)
      glLineWidth(data.width);

    glBegin(data.type);
      for(Point node : path)
        glVertex2i(node.x, YD_MAX - node.y);
    glEnd();
  }
}

void drawWindow() {
  glClear(GL_COLOR_BUFFER_BIT);

  
  for(DrawingData data : g_staticDrawings)
    drawPaths(data);

  for(TextDrawingData data : g_texts)
    drawText(data);

  glPushMatrix();
  drawPaths(g_planeDrawing
    .rotate(g_planeRotation+M_PI/2)
    .translate(g_planeOffset)
  );
  drawText(TextDrawingData(
    "position: x:" + std::to_string((int)g_planeOffset.x)
    + " y:" + std::to_string((int)(YD_MAX-g_planeOffset.y))
    + " | velocity: " + std::to_string(g_planeVelocity)
    + " | rotation: " + std::to_string(-(int)(g_planeRotation*180/M_PI+90)),
    Color(0x000000),
    Point(0,10),
    GLUT_BITMAP_HELVETICA_12
  ));

  glPopMatrix();

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

  srand((unsigned)time(0));
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(XD_MAX, YD_MAX);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("OpenGL - Anima Aviao-STHEFANO SCHIAVON");
  glutSpecialFunc(onSpecialInput);
  glutDisplayFunc(drawWindow);
  glutReshapeFunc(onChangeWindowSize);
  updateFrame(16);
  setbuf(stdin,NULL);
  init();
  glutMainLoop();
  return 0;
}
