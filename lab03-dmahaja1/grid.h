#pragma once

/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/yyr8mdoh
*/

#include <string>

/**
 * The Grid class provides a two-dimensional grid onto which a program can draw.
 * It serves as an intermediate drawing space so a picture can be prepared
 * before it is written to the terminal.
 */
class Grid {
  public:
    /**
     * Creates a new grid.
     */
    Grid();

    /**
     * Cleans up the resources used by the grid.
     */
    virtual ~Grid();

    /**
     * Places a symbol in the specified location on the grid.
     * @param x The X coordinate in the grid at which the symbol will be placed.
     *          Valid values range from zero to one less than the width of the
     *          grid.
     * @param y The Y coordinate in the grid at which the symbol will be placed.
     *          Valid values range from zero to one less than the height of the
     *          grid.
     * @param s The character to put in the grid at the specified location.
     */
    virtual void placeSymbol(int x, int y, char s);

    /**
     * Creates a string with the contents of this grid.
     * @return A string which represents this grid's contents.
     */
    virtual std::string toString();

    /**
     * Prints the grid.  This displays the contents of the grid by writing it to
     * cout.
     */
    virtual void print();
    
  private:
    /** The character data used by the grid. */
    char* data;
    /** The width of the grid. */
    int width;
    /** The height of the grid. */
    int height;
    /** The initial background symbol of the grid. */
    char backgroundSymbol;
};
