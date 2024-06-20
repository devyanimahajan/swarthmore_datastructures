/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/yyr8mdoh
*/

#include "linkedStack.h"

using namespace std;

// NOTE: Most of the method bodies in this class will only require a single line
// of code!

template <typename T> LinkedStack<T>::LinkedStack() {
    this->actualStack = new STLList<T>();
}

template <typename T> void LinkedStack<T>::push(T element) {
    this->actualStack->insertFirst(element);
}

template <typename T> T LinkedStack<T>::pop() {
    return this->actualStack->removeFirst();
}

template <typename T> void LinkedStack<T>::insert(T element) {
    // To "insert" into a stack is to push onto it.  So when we are told to
    // insert, we will push.
    this->push(element);
}

template <typename T> T LinkedStack<T>::remove() {
    return this->pop();
}

template <typename T> int LinkedStack<T>::getSize() {
    return this->actualStack->getSize();
}

template <typename T> bool LinkedStack<T>::isEmpty() {
    return this->actualStack->isEmpty();
}

template <typename T> T LinkedStack<T>::peek() {
    return this->actualStack->getFirst();
}
