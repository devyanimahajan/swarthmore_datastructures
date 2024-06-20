/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/yyr8mdoh
*/

#include "linkedQueue.h"

using namespace std;

// NOTE: Most of the method bodies in this class will only require a single line
// of code!

template <typename T> LinkedQueue<T>::LinkedQueue() {
    this->actualQueue = new STLList<T>();
}

template <typename T> void LinkedQueue<T>::enqueue(T element) {
     this->actualQueue->insertLast(element);
}

template <typename T> T LinkedQueue<T>::dequeue() {
    return this->actualQueue->removeFirst();
}

template <typename T> void LinkedQueue<T>::insert(T element) {
    // NOTE: for a hint on how to implement this, see LinkedStack<T>::insert
    this->enqueue(element);
}

template <typename T> T LinkedQueue<T>::remove() {
    //throw runtime_error("Not yet implemented: LinkedQueue::remove");
    return this->dequeue();
}

template <typename T> int LinkedQueue<T>::getSize() {
    return this->actualQueue->getSize();
}

template <typename T> bool LinkedQueue<T>::isEmpty() {
    return this->actualQueue->isEmpty();
}

template <typename T> T LinkedQueue<T>::peek() {
    return this->actualQueue->getFirst();
}
