/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/yyr8mdoh
*/

#include "helpers.h"

template <typename T> vector<T> dynamicListToStaticVector(List<T>* list) {
    //throw runtime_error("Not yet implemented: dynamicListToStaticVector");
    //make vector
    vector<T> vec;
    //find length of list
    int length = list->getSize();
    //counted loop: for length of list
    for(int i = 0; i<length; i++){
      //read list value and put into vector
      vec.push_back(list->get(i));
    }
    //return vector
    return vec;
}
