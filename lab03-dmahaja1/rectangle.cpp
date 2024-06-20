/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/yyr8mdoh
*/
#include "verticalLine.h"
#include "horizontalLine.h"
#include "rectangle.h"


Rectangle::Rectangle(int x, int y, int width, int height, char symbol){
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
  this->symbol = symbol;
}

void Rectangle::draw(Grid* grid){
  // for loop iterating through each horizontal line
  for(int y = this->y; y < this->y + this->height; y ++){
    HorizontalLine* line = new HorizontalLine(this->x, y, this->width,this->symbol);
    line->draw(grid);
    delete line;
  }
   

}
