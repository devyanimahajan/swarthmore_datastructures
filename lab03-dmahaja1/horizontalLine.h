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

// TODO: Declare your HorizontalLine class here.

class HorizontalLine : public Shape{
  private:
    int x;
    int y;
    int length;
    char symbol;
  public:
    void draw(Grid* grid);
    HorizontalLine(int x, int y, int length, char symbol);


};
