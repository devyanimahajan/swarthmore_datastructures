#pragma once

/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/yyr8mdoh
*/

#include "grid.h"

/**
 * A class representing a shape.
 */
class Shape {
  public:
    virtual ~Shape() {
    }

    /**
     * Draws this shape on the provided grid.
     * @param grid The grid onto which to draw the shape.
     */
    virtual void draw(Grid* grid) = 0;
};
