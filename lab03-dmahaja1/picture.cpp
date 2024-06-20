/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/yyr8mdoh
*/

#include <iostream>
#include <stdexcept>

#include "picture.h"

using namespace std;

Picture::Picture() {
    this -> numberOfShapes = 0;
    //initialise it here
    //dynamically allocated in addShape
}

Picture::~Picture() {
  //make sure all the shapes are deleted, may be overkill
  for(int i = 0; i < this->numberOfShapes; i++){
    delete this->shapes[i];
  }
  // delete shapes array
  delete[] this->shapes;

}

string Picture::toString() {
    Grid* grid = new Grid();
    for(int i=0;i<this->numberOfShapes;i++){//iterate through shapes array
      ((this->shapes)[i])->draw(grid); //insert each shape to grid
    }
    return grid->toString();//return string
}

void Picture::print() {
    cout << this->toString() << endl;
}

void Picture::addShape(Shape* shape) {
    int index = this->numberOfShapes;
    //if adding first shape, dynamically allocate the shapes array
    if (index == 0){
      this->shapes = new Shape*[50];
    }
    (this->shapes)[index] = shape; //add new shape to shapes array, at the end of the array
    this->numberOfShapes = index+1; //increment number of shapes
}
