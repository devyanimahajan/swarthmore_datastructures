/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/yyr8mdoh
*/

#include <stdexcept>

#include "horizontalLine.h"
#include "point.h"
#include "rectangle.h"
#include "shape.h"
#include "verticalLine.h"
#include "shapeConstants.h"

using namespace std;

Shape* createPoint(int x, int y, char appearance) {
    #ifdef DECLARED_POINT
    return new Point(x, y, appearance);
    #else
    return nullptr;
    #endif
}

Shape* createHorizontalLine(int x, int y, int length, char appearance) {
    #ifdef DECLARED_HORIZONTALLINE
    return new HorizontalLine(x, y, length, appearance);
    #else
    return nullptr;
    #endif
}

Shape* createVerticalLine(int x, int y, int length, char appearance) {
    #ifdef DECLARED_VERTICALLINE
    return new VerticalLine(x, y, length, appearance);
    #else
    return nullptr;
    #endif
}

Shape* createRectangle(int x, int y, int width, int height, char appearance) {
    #ifdef DECLARED_RECTANGLE
    return new Rectangle(x, y, width, height, appearance);
    #else
    return nullptr;
    #endif
}
