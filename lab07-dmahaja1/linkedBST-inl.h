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
#include <vector>

#include "adts/list.h"
#include "adts/queue.h"
#include "adts/stlList.h"
#include "adts/stlQueue.h"

#include "linkedBSTNode.h"
#include "helpers.h"

using std::pair;
using std::runtime_error;
using std::vector;

template <typename K, typename V> LinkedBST<K, V>::LinkedBST() {
    this->size = 0;
    this->root = nullptr;
}

template <typename K, typename V> LinkedBST<K, V>::~LinkedBST() {
    // To do: implement the destructor
    // use recursive helper function
    this->deleteSubtree(this->root);
    delete this->root;
}

template <typename K, typename V> int LinkedBST<K, V>::getSize() {
    return this->size;
}

template <typename K, typename V> bool LinkedBST<K, V>::isEmpty() {
    return (this->getSize() == 0);
}

template <typename K, typename V> void LinkedBST<K, V>::insert(K key, V value) {
    
    if(this->isEmpty()){
        LinkedBSTNode<K, V>* node = new LinkedBSTNode<K, V>(key,value);
        this->root = node;
    }

    else{
        insertInSubtree(this->root,key,value);
    }
    this->size += 1;
    return;

}

template <typename K, typename V> void LinkedBST<K, V>::update(K key, V value) {
    if(this->isEmpty()){
        throw runtime_error("Empty tree: LinkedBST<K,V>::update");
    }
    
    else{
        this->updateInSubtree(this->root,key,value);
    }
}

template <typename K, typename V> V LinkedBST<K, V>::get(K key) {
    
    if(this->isEmpty()){
        throw runtime_error("Empty tree: LinkedBST<K,V>::get");
    }
    
    else{
        return this->findInSubtree(this->root,key);
    }
}

template <typename K, typename V> bool LinkedBST<K, V>::contains(K key) {
    //throw runtime_error("Not yet implemented: LinkedBST<K,V>::contains");
    
    if(this->isEmpty()){
        return false;
    }
    if(key < this->getMinKey() || key > this->getMaxKey()){
        return false;
    } 
    else {
        return this->containsInSubtree(this->root,key);
    }
}


template <typename K, typename V> void LinkedBST<K, V>::remove(K key) {
    //throw runtime_error("Not yet implemented: LinkedBST<K,V>::remove");
    if(this->isEmpty()){
        throw runtime_error("Empty tree: LinkedBST<K,V>::remove");
    }
    if (!this->contains(key)) {
        throw runtime_error("Key not present: LinkedBST<K,V>::remove");
    }
    this->size -= 1;
    this->removeFromSubtree(this->root,key);

}

template <typename K, typename V> vector<K> LinkedBST<K, V>::getKeys() {
    //throw runtime_error("Not yet implemented: LinkedBST<K,V>::getKeys");
    vector<K> vec;
    if(!(this->isEmpty())){

        vector<pair<K, V>> pairVec = this->traverseInOrder();
        for(int i = 0; i< pairVec.size(); i++){
            //std::cout<<pairVec[i].first<<std::endl;
            vec.push_back(pairVec[i].first);
        }

    }
    return vec;   
}

template <typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::getItems() {
    //throw runtime_error("Not yet implemented: LinkedBST<K,V>::getItems");
    if(this->isEmpty()){
        throw runtime_error("Empty Tree");
    }
    return this->traverseInOrder();
}

template <typename K, typename V> int LinkedBST<K, V>::getHeight() {
    if(this->isEmpty()){
        throw runtime_error("Empty Tree");
    }
    else{
        return this->getHeightInSubtree(this->root);
    }
}

template <typename K, typename V> K LinkedBST<K, V>::getMaxKey() {
    if(this->isEmpty()){
        throw runtime_error("Empty Tree");
    }
    else{
        return this->getMaxInSubtree(this->root).first;
    }
}

template <typename K, typename V> K LinkedBST<K, V>::getMinKey() {
    if(this->isEmpty()){
        throw runtime_error("Empty Tree");
    }
    else{
        return this->getMinInSubtree(this->root).first;
    }

    
}

template <typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::traversePreOrder() {
    if(this->isEmpty()){
        throw runtime_error("Empty tree: LinkedBST<K,V>::traversePreOrder");
    }
    
    else{
        //create a list for traversal
        STLList<pair<K, V>>* preList = new STLList<pair<K, V>>();
        this->buildPreOrderTraversal(this->root,preList);
        //list has been built
        //convert list to a vector
        vector<pair<K, V>> preVector = dynamicListToStaticVector(preList);
        //delete list
        delete preList;
        return preVector;

    }
    

}

template <typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::traverseInOrder() {
    //throw runtime_error("Not yet implemented: LinkedBST<K,V>::traverseInOrder");
    if(this->isEmpty()){
        throw runtime_error("Empty tree: LinkedBST<K,V>::traverseInOrder");
    }
    
    else{
        //create a list for traversal
        STLList<pair<K, V>>* inList = new STLList<pair<K, V>>();
        this->buildInOrderTraversal(this->root,inList);
        //list has been built
        //convert list to a vector
        vector<pair<K, V>> inVector = dynamicListToStaticVector(inList);
        //delete list
        delete inList;
        return inVector;

    }
}

template <typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::traversePostOrder() {
    //throw runtime_error("Not yet implemented: LinkedBST<K,V>::traversePostOrder");
    if(this->isEmpty()){
        throw runtime_error("Empty tree: LinkedBST<K,V>::traversePostOrder");
    }
    
    else{
        //create a list for traversal
        STLList<pair<K, V>>* postList = new STLList<pair<K, V>>();
        this->buildPostOrderTraversal(this->root,postList);
        //list has been built
        //convert list to a vector
        vector<pair<K, V>> postVector = dynamicListToStaticVector(postList);
        //delete list
        delete postList;
        return postVector;

    }
}

template <typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::traverseLevelOrder() {
    //throw runtime_error("Not yet implemented: LinkedBST<K,V>::traverseLevelOrder");
    if(this->isEmpty()){
        throw runtime_error("Empty tree: LinkedBST<K,V>::traverseLevelOrder");
    }
    
    else{
        //create a vector for traversal
        vector<pair<K, V>> levelVector;
        
        //create queue
        STLQueue<LinkedBSTNode<K, V>*>* Q = new STLQueue<LinkedBSTNode<K, V>*>();
        //queue has been built
        Q->enqueue(this->root);
        while(!Q->isEmpty()){
            LinkedBSTNode<K, V>*current = Q->dequeue();
            levelVector.push_back(make_pair(current->getKey(), current->getValue()));
            if(current->getLeft() != nullptr){
                Q->enqueue(current->getLeft());
            }
            if(current->getRight() != nullptr){
                Q->enqueue(current->getRight());
            }
        }

        //delete queue
        //delete Q;
        return levelVector;

    }
}

template <typename K, typename V> void LinkedBST<K, V>::checkInvariants() {
    if (this->countNodes(this->root) != this->size) {
        throw runtime_error(
            "Problem in BST: Node count doesn't match tree size");
    }
    if (this->root != nullptr) {
        // The bounds provided here are arbitrary because the false arguments
        // indicate that they do not apply.  But we need a value of type K to
        // fill this parameter since we don't have globally min/max K values
        // generically.
        this->verifyKeysBoundedBy(this->root, false, this->root->getKey(),
                                  false, this->root->getKey());
    }
}
