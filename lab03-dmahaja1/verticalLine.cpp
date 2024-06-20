/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/yyr8mdoh
*/

#include "verticalLine.h"


VerticalLine::VerticalLine(int x, int y, int length, char symbol){
  this -> x = x;
  this -> y = y;
  this -> length = length;
  this -> symbol = symbol;
}


void VerticalLine::draw(Grid* grid){
  int limit = this->y+this->length;
  // use for loop to iterate through all y variables in the line
  for(int i = this->y;i<limit;i++){
    grid->placeSymbol(this->x, i, this->symbol);
  }
}
