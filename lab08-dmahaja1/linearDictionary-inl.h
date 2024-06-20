/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/yyr8mdoh
*/

#include <stdexcept>
using std::pair;
using std::runtime_error;
using std::vector;

template <typename K, typename V> LinearDictionary<K, V>::LinearDictionary() {
    this->dict = new vector<pair<K, V>>();
}

template <typename K, typename V> LinearDictionary<K, V>::~LinearDictionary() {
    this->dict->clear();
    delete this->dict;
}

template <typename K, typename V> int LinearDictionary<K, V>::getSize() {
    return this->dict->size();
}

template <typename K, typename V> bool LinearDictionary<K, V>::isEmpty() {
    return (this->dict->empty());
}

template <typename K, typename V>
void LinearDictionary<K, V>::insert(K key, V value) {
    if(!this->contains(key)){
        this->dict->push_back(std::make_pair(key,value));
    }
    else{
        throw runtime_error("Key already exists: LinearDictionary<K,V>::insert");
    }
    
}

template <typename K, typename V>
void LinearDictionary<K, V>::update(K key, V value) {
    //throw runtime_error("Not yet implemented: LinearDictionary<K,V>::update");
    for(int i = 0; i < this->dict->size(); i++){
        if(this->dict->at(i).first == key){
            this->dict->at(i).second = value;
            return;
        }
    }
    throw runtime_error("Key not found: LinearDictionary<K,V>::update");
}

template <typename K, typename V> V LinearDictionary<K, V>::get(K key) {
    for(auto  i = 0; i < this->dict->size(); i++){
        if(this->dict->at(i).first == key){
            return this->dict->at(i).second;
        }
    }
    throw runtime_error("Key not found: LinearDictionary<K,V>::get");
}

template <typename K, typename V> bool LinearDictionary<K, V>::contains(K key) {
    for(int i = 0; i < this->dict->size(); i++){
        if(this->dict->at(i).first == key){
            return true;
        }
    }
    return false;
}

template <typename K, typename V> void LinearDictionary<K, V>::remove(K key) {
    for (int it = 0; it < this->getSize(); it++){
        if(this->dict->at(it).first == key){
            this->dict->erase(this->dict->begin()+it,this->dict->begin()+it+1);
            return;
        }
    }
    throw runtime_error("Key not found: LinearDictionary<K,V>::remove");
        
}

template <typename K, typename V> vector<K> LinearDictionary<K, V>::getKeys() {
    vector<K> allKeys;
    for(int i = 0; i < this->dict->size(); i++){
        allKeys.push_back(this->dict->at(i).first);
    }
    return allKeys;
}

template <typename K, typename V>
vector<pair<K, V>> LinearDictionary<K, V>::getItems() {
    vector<pair<K, V>> allItems;
    for(int i = 0; i < this->dict->size(); i++){
        allItems.push_back(std::make_pair(this->dict->at(i).first,this->dict->at(i).second));
    }
    return allItems;

}

template <typename T> void removeFromVector(vector<T> &list, int index){
  if(index < 0 || index >= list.size()){
    throw runtime_error("index out of range in removeFromVector");
  }
  list.erase(list.begin()+index, list.begin()+index+1);
}

// TODO: put any other definitions here
