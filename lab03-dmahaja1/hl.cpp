/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/yyr8mdoh
*/

#include "horizontalLine.h"
#include "point.h"


HorizontalLine::HorizontalLine(int x, int y, int length, char symbol){
  // initialise variables
  this -> x = x;
  this -> y = y;
  this -> length = length;
  this -> symbol = symbol;
}

void HorizontalLine::draw(Grid* grid){
  /*
  for (int i = 0; i < this->length-1; i++){
    Point* point = new Point(x+i,y,this->symbol);
    point->draw(grid);
    delete point;
  }
  */
  

  int limit = 1+ this->x+this->length;
  for(int i = this->x;i<limit-1;i++){
    grid->placeSymbol(i, this->y, this->symbol);
  }
}
