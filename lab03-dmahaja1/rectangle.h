#pragma once

/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/yyr8mdoh
*/

#include "shape.h"

// TODO: Declare your Rectangle class here.
class Rectangle : public Shape{
  private:
    int x;
    int y;
    int width;
    int height;
    char symbol;
  public:
    void draw(Grid* grid);
    Rectangle(int x, int y, int width, int height, char symbol);


};
