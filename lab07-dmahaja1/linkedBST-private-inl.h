/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/yyr8mdoh
*/

#include <stdexcept>
#include <utility>
#include <algorithm>

#include "adts/list.h"
#include "adts/stlList.h"

using std::runtime_error;

template <typename K, typename V>
V LinkedBST<K, V>::findInSubtree(LinkedBSTNode<K, V>* current, K key) {
    //throw runtime_error("Not yet implemented: LinkedBST<K,V>::findInSubtree");
    if(key < this->getMinKey() || key > this->getMaxKey()){
        throw runtime_error("Key not in tree: LinkedBST<K,V>::get");
    }
    
    else if(key == current->getKey()){
        return current->getValue();

    }
    else if(key<current->getKey()){//going left
        return this->findInSubtree(current->getLeft(),key);
    }
    else{//going right
        return this->findInSubtree(current->getRight(),key);
    }
}

template <typename K, typename V>
bool LinkedBST<K, V>::containsInSubtree(LinkedBSTNode<K, V>* current, K key) {
    if (current == nullptr) { //reached end without finding 
        return false;
    }else if(key == current->getKey()){
        return true;
    }
    else if(key<current->getKey()){//going left
        return this->containsInSubtree(current->getLeft(),key);
    }
    else{//going right
        return this->containsInSubtree(current->getRight(),key);
    }
}

template <typename K, typename V>
void LinkedBST<K, V>::updateInSubtree(LinkedBSTNode<K, V>* current, K key,
                                      V value) {
    //throw runtime_error("Not yet implemented: LinkedBST<K,V>::updateInSubtree");
    if(key < this->getMinKey() || key > this->getMaxKey()){
        throw runtime_error("Key not in tree: LinkedBST<K,V>::update");
    }
    
    else if(key == current->getKey()){
        current->setValue(value);

    }
    else if(key<current->getKey()){//going left
        return this->updateInSubtree(current->getLeft(),key,value);
    }
    else{//going right
        return this->updateInSubtree(current->getRight(),key,value);
    }
}

template <typename K, typename V>
int LinkedBST<K, V>::getHeightInSubtree(LinkedBSTNode<K, V>* current) {
    if (current == nullptr) { 
        return -1;
    }
    else{
            int leftHeight = this->getHeightInSubtree(current->getLeft());
            int rightHeight = this->getHeightInSubtree(current->getRight());
            if (leftHeight > rightHeight){
                return leftHeight +1;
            }
            else {
                return rightHeight +1;
            }
        }
    }
    





template <typename K, typename V>
pair<K, V> LinkedBST<K, V>::getMinInSubtree(LinkedBSTNode<K, V>* current) {
    //throw runtime_error("Not yet implemented: LinkedBST<K,V>::getMinInSubtree");
    if(current->getLeft()==nullptr){
        return make_pair(current->getKey(), current->getValue());
    }
    else{
        return this->getMinInSubtree(current->getLeft());
    }
}



template <typename K, typename V>
pair<K, V> LinkedBST<K, V>::getMaxInSubtree(LinkedBSTNode<K, V>* current) {
    if(current->getRight()==nullptr){
        return make_pair(current->getKey(), current->getValue());
    }
    else{
        return this->getMaxInSubtree(current->getRight());
    }
}





template <typename K, typename V>
LinkedBSTNode<K, V>*
LinkedBST<K, V>::insertInSubtree(LinkedBSTNode<K, V>* current, K key, V value) {
    //throw runtime_error("Not yet implemented: LinkedBST<K,V>::insertInSubtree");
    if(key<current->getKey()){ //going left
        if(current->getLeft()==nullptr){//inserting node here
            LinkedBSTNode<K, V>* node = new LinkedBSTNode<K, V>(key,value);
            current->setLeft(node);
            return current; //or perhaps return node?
        }
        else{
            return insertInSubtree(current->getLeft(),key,value);
        }
    } 
    else{ //going right
        if(current->getRight()==nullptr){//inserting node here
            LinkedBSTNode<K, V>* node = new LinkedBSTNode<K, V>(key,value);
            current->setRight(node);
            return current; //or perhaps return node?
        }
        else{
            return insertInSubtree(current->getRight(),key,value);
        }
    }
    
}



template <typename K, typename V>
LinkedBSTNode<K, V>*
LinkedBST<K, V>::removeFromSubtree(LinkedBSTNode<K, V>* current, K key) {
    // Check if nullptr passed
    if (current == nullptr){
        return nullptr;
    }
    // Check if key is in root of subtree (current) node
    if (current->getKey()==key){
        if (this->getHeightInSubtree(current)==0){// leaf node
            delete current;
            //current = nullptr;
            return nullptr;
        }
        else if(this->getHeightInSubtree(current)==1){// one above leaf node, one or two children
            if(current->getLeft()!=nullptr){//Left child exists
                current->setKey(current->getLeft()->getKey());
                current->setValue(current->getLeft()->getValue());
                delete current->getLeft();
                current->setLeft(nullptr);
            }    
            else{ //Left child does not exist, right does
                current->setKey(current->getRight()->getKey());
                current->setValue(current->getRight()->getValue());
                delete current->getRight();
                current->setRight(nullptr);
            }
            
        }
        else{ // current is not leaf or one above leaf 
            if (current->getLeft()!=nullptr){// left subtree exists
                pair<K, V> maxPair = this->getMaxInSubtree(current->getLeft());
                current->setKey(maxPair.first);
                current->setValue(maxPair.second);
                //this->removeFromSubtree(current->getLeft(),maxPair.first);
                current->setLeft(this->removeFromSubtree(current->getLeft(),maxPair.first));

            }
            else{// left subtree does not exist, right does
                pair<K, V> minPair = this->getMinInSubtree(current->getRight());
                current->setKey(minPair.first);
                current->setValue(minPair.second);
                //this->removeFromSubtree(current->getRight(),minPair.first);
                current->setRight(this->removeFromSubtree(current->getRight(),minPair.first));
            }
            
        }
    }

    else if (current->getKey()>key){ // key not in root, going left
        current->setLeft(this->removeFromSubtree(current->getLeft(),key));
    }
    else { // going right
        current->setRight(this->removeFromSubtree(current->getRight(),key));
    }
    return current;
}

template <typename K, typename V>
void LinkedBST<K, V>::deleteSubtree(LinkedBSTNode<K, V>* current) {
    //throw runtime_error("Not yet implemented: LinkedBST<K,V>::deleteSubtree");
    if(current == nullptr){
        return;
    }
    if(current->getLeft()==nullptr && current->getRight()==nullptr){
        delete current;
        return;
    }
    else{
        this->deleteSubtree(current->getLeft());
        this->deleteSubtree(current->getRight());
    }
}

template <typename K, typename V>
void LinkedBST<K, V>::buildPreOrderTraversal(LinkedBSTNode<K, V>* current,
                                             List<pair<K, V>>* list) {
    //insert root into list
    list->insertLast(make_pair(current->getKey(), current->getValue()));
    //check for null left 
    if(current->getLeft()!=nullptr){
        buildPreOrderTraversal(current->getLeft(),list);
    }
    if(current->getRight()!=nullptr){
        buildPreOrderTraversal(current->getRight(),list);
    }
    return;
}

template <typename K, typename V>
void LinkedBST<K, V>::buildInOrderTraversal(LinkedBSTNode<K, V>* current,
                                            List<pair<K, V>>* list) {
    //throw runtime_error("Not yet implemented: LinkedBST<K,V>::buildInOrder");

    if(current->getLeft()!=nullptr){
        buildInOrderTraversal(current->getLeft(),list);
    }
    list->insertLast(make_pair(current->getKey(), current->getValue()));
    if(current->getRight()!=nullptr){
        buildInOrderTraversal(current->getRight(),list);
    }
    return;
}

template <typename K, typename V>
void LinkedBST<K, V>::buildPostOrderTraversal(LinkedBSTNode<K, V>* current,
                                              List<pair<K, V>>* list) {
    //throw runtime_error("Not yet implemented: LinkedBST<K,V>::buildPostOrder");
    if(current->getLeft()!=nullptr){
        buildPostOrderTraversal(current->getLeft(),list);
    }
    if(current->getRight()!=nullptr){
        buildPostOrderTraversal(current->getRight(),list);
    }
    list->insertLast(make_pair(current->getKey(), current->getValue()));
    return;

}

template <typename K, typename V>
int LinkedBST<K, V>::countNodes(LinkedBSTNode<K, V>* current) {
    if (current == nullptr) {
        return 0;
    } else {
        return this->countNodes(current->getLeft()) +
               this->countNodes(current->getRight()) + 1;
    }
}

template <typename K, typename V>
void LinkedBST<K, V>::verifyKeysBoundedBy(LinkedBSTNode<K, V>* current,
                                          bool minApplies, K minBound,
                                          bool maxApplies, K maxBound) {
    if (minApplies && current->getKey() < minBound) {
        throw runtime_error("LinkedBST::verifyKeysBoundedBy: a node has a "
                            "right descendent with lesser key");
    }
    if (maxApplies && current->getKey() > maxBound) {
        throw runtime_error("LinkedBST::verifyKeysBoundedBy: a node has a left "
                            "descendent with greater key");
    }
    if (current->getLeft() != nullptr) {
        verifyKeysBoundedBy(current->getLeft(), minApplies, minBound, true,
                            current->getKey());
    }
    if (current->getRight() != nullptr) {
        verifyKeysBoundedBy(current->getRight(), true, current->getKey(),
                            maxApplies, maxBound);
    }
}
