/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/yyr8mdoh
*/

#include <stdexcept>

/* ADTs */
#include "adts/list.h"
#include "adts/orderedCollection.h"
#include "adts/queue.h"
#include "adts/stack.h"

/* Implementations of above ADTs */
#include "adts/stlList.h"
#include "linkedQueue.h"
#include "linkedStack.h"

#include "maze.h"

using namespace std;

Maze::Maze(int width, int height) {

    this->height = height;
    this->width = width;
    this->positions = new Position**[width];
    for (int x = 0; x < width; x++){
      this->positions[x] = new Position*[height];
      for (int y = 0; y < height; y ++){
        this->positions[x][y] = new Position(x,y);  
      }
    }  
}

Maze::~Maze() {
    for(int column = 0; column<this->width; column++)
        for(int row = 0; row<this->height; row++)
            delete  this->positions[column][row];
    for(int column = 0; column<this->width; column++)
        delete [] this->positions[column];
    
    delete [] this->positions;
}

int Maze::getWidth() {
    return this->width;
}

int Maze::getHeight() {
    return this->height;
}

bool Maze::isWall(int x, int y) {
    return this->positions[x][y]->isWall();
}

void Maze::setWall(int x, int y) {
    this->positions[x][y]->setWall();
}

List<Position*>* Maze::solveBreadthFirst() {
    // BFS needs a queue data structure, first explore the positions visited first
    LinkedQueue<Position*> * Q = new LinkedQueue<Position*>();
    List<Position*>* solution = this->solve(Q);
    delete Q;
    return(solution);   
}

List<Position*>* Maze::solveDepthFirst() {
    // DFS needs a stack data structure, first explore the positions visited last
    return(this->solve(new LinkedStack<Position*>()));
}

List<Position*>* Maze::solve(OrderedCollection<Position*>* exploration) {
    Position * beginPosition = this->positions[0][0];
    Position * endPosition = this->positions[this->getWidth()-1][this->getHeight()-1];
    bool solved = false; // if not solved
    // initialise the data structure
    beginPosition->setVisited();
    exploration->insert(beginPosition);
    
    
    while(!(solved||exploration->isEmpty())) {// haven't found a solution or no more positions to explore
        Position* currentPosition = exploration->remove();
        if(currentPosition==endPosition){ // at the end of the maze
            solved = true;// Done!
        }
        else {
            List<Position*>* neighborsList = this->getNeighbors(currentPosition); // get the neghbors list
            while(!neighborsList->isEmpty()){ //scan through the neighbors list
                Position* neighbor = neighborsList->removeFirst();
                if (!(neighbor->isWall()||neighbor->isVisited())){// suitable to insert
                    neighbor->setVisited();
                    neighbor->setPrevious(currentPosition);
                    exploration->insert(neighbor);
                }
                
            }
            delete neighborsList;
        }
    }
    if(! solved){
	//delete exploration;
        return nullptr; // no solution exists - have visited all the positions
    }
    else{ // maze has been solved
    // create a list to store the solution
    List<Position*>* solution = new STLList<Position*>();
    solution->insertLast(endPosition); // insert last position in solution
    Position* pos = endPosition; // set up index pointer 'pos', use it to traverse the solution list
    while (pos!= beginPosition){ // have come to first position
        pos = pos->getPrevious(); // move to the previous position
        solution->insertFirst(pos); // insert in solution        
    }
    //delete exploration;
    return solution;
    }
}

List<Position*>* Maze::getNeighbors(Position* position) {
    /*you should explore neighboring spaces in the following order in your getNeighbors method: 
    up, left, right, and then down.*/
    List<Position*>* neighborsList = new STLList<Position*>();
    int x = position->getX();
    int y = position->getY();
    if(y!=0){// has up neighbor
        neighborsList->insertLast(this->positions[x][y-1]);}
    if(x!=0){//has left neighbor
        neighborsList->insertLast(this->positions[x-1][y]);}
    if(x!=this->getWidth()-1){//has right neighbor
        neighborsList->insertLast(this->positions[x+1][y]);}
    if(y!=this->getHeight()-1){//has down neighbor
        neighborsList->insertLast(this->positions[x][y+1]);}
    return neighborsList;
}
