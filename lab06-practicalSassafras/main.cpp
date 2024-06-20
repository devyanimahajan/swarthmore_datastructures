/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/yyr8mdoh
*/

#include <iostream>
#include <cstring>
#include <utility>
#include <exception>

#include "maze.h"
#include "mazeUtils.h"

using namespace std;

int main(int argc, char** argv) {
    try {
      if (argc !=3 ){ // arguments not exactly 2
        throw runtime_error("incorrect number of arguments, 2 needed -  you entered "+ to_string(argc));
      }
      if((std::strcmp(argv[2],"breadth")!=0) && (std::strcmp(argv[2],"depth")!=0)){ // entered something other than breadth or depth for argument# 2
        throw runtime_error("please enter either \"breadth\" or \"depth\"");
      }
      Maze* maze = loadMap(argv[1]);
      List<Position*>* answer;

      if (std::strcmp(argv[2],"breadth")==0){ // BFS
        answer =  maze->solveBreadthFirst();
      } else { // DFS
        answer = maze->solveDepthFirst();
      }
      // Print answer if answer exists else say no answer exists
      if (answer != nullptr){
        cout<<renderAnswer(maze,answer);}
      else{
        cout<<"no solution exists \n";
      }
      delete answer;
      delete maze;
    } // print error message and exit
    catch( runtime_error e){
      cout<<e.what()<<endl;
    }
    return 0;
}
