/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/yyr8mdoh
*/

#include "grid.h"
#include "shape.h"
#include "point.h"
#include "horizontalLine.h"
#include "verticalLine.h"
#include "rectangle.h"
#include "picture.h"
#include <iostream>

using namespace std;

int main() {

    // You can put anything you like here.  This file exists so that you can
    // experiment with your code.  For instance, the following might be a useful
    // test after you've written your Point class.

    Shape* s1 = new Point(5,3,'x');
    //Shape* s2 = new HorizontalLine(1,1,3,'h');
    //Shape* s3 = new VerticalLine(2,2,2,'v');
    //Shape* s4 = new Rectangle(2,3,3,5,'R');

    Picture* pic = new Picture();
    pic->addShape(s1);
    cout <<"added shape"<<endl;
    //pic->addShape(s2);
    //pic->addShape(s3);
    //pic->addShape(s4);
    pic->print();

/*
    Grid* grid = new Grid();
    s1->draw(grid);
    s2->draw(grid);
    s3->draw(grid);
    s4->draw(grid);

    cout << grid->toString() << endl;
    delete grid;


    //delete pic;
    delete s1;
    delete s2;
    delete s3;
    delete s4;

    //delete pic;
*/
    return 0;
}
