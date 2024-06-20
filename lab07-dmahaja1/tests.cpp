/*
  Copyright (c) 2020
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, M. Gagne, L. Meeden, Z. Palmer, A. Soni, M. Wehar
  Distributed as course material for Fall 2020
  CPSC 035: Data Structures and Algorithms
  https://tinyurl.com/yyr8mdoh
*/

#include <cmath>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

#include <UnitTest++/UnitTest++.h>

#include "adts/BST.h"
#include "adts/list.h"
#include "linkedBST.h"
#include "linkedBSTNode.h"

using namespace std;

/**
 * This helper function will build a small BST on which we can perform
 * experiments.  We can call the methods of the BST
 * in a specific order to make sure it puts the nodes where we want them
 * (assuming, of course, that the insert and get functions work correctly).
 * Our tree will look like this:
 * @verbatim
 *         6
 *        / \
 *       /   \
 *      2     7
 *     / \     \
 *    1   4     9
 *       /
 *      3
 * @endverbatim
 * @return An example BST.  The caller is responsible for deleting this BST.
 */
LinkedBST<int, string>* makeExampleBST() {
    LinkedBST<int, string>* bst = new LinkedBST<int, string>();
    bst->insert(6, "6");
    bst->insert(2, "2");
    bst->insert(7, "7");
    bst->insert(1, "1");
    bst->insert(4, "4");
    bst->insert(9, "9");
    bst->insert(3, "3");
    bst->checkInvariants();
    return bst;
}

TEST(emptyBST) {
    LinkedBST<int, string>* bst = new LinkedBST<int, string>();
    CHECK_EQUAL(0, bst->getSize());
    CHECK(bst->isEmpty());
    bst->checkInvariants();
    delete bst;
}

TEST(exampleBST) {
    // Since we have to respect the BST interface -- we can't look directly at
    // the BST nodes -- we have to test the example BST to make sure that it
    // behaves like we'd think.  If this test fails, then either the insert or
    // the get method is broken and it's hard to tell which.
    // The upside is that we test both the insert and get functions with this
    // test.
    LinkedBST<int, string>* bst = makeExampleBST();
    for (int i = 1; i <= 9; i++) {
        if (i != 5 && i != 8) {
            CHECK_EQUAL(to_string(i), bst->get(i));
        }
    }
    delete bst;
}

TEST(exampleBSTSize) {
    LinkedBST<int, string>* bst = makeExampleBST();
    CHECK_EQUAL(7, bst->getSize());
    CHECK(!bst->isEmpty());
    delete bst;
}

// NOTE: Be sure to make frequent use of the checkInvariants method
// which verifies that your BST contains the correct number of nodes
// and has properly implemented the BST property.

TEST(updateInteriorNode) {
    LinkedBST<int, string>* bst = makeExampleBST();
    CHECK_EQUAL("4", bst->get(4));
    bst->update(4, "-1");
    CHECK_EQUAL("-1", bst->get(4));
    bst->checkInvariants();
    bst->update(4, "4");
    CHECK_EQUAL("4", bst->get(4));
    bst->checkInvariants();
    delete bst;
}

// TODO: test LinkedBST<K,V>::contains

TEST(contains){
  LinkedBST<int, string>* bst = makeExampleBST();
  CHECK_EQUAL(bst->contains(3), true);
  delete bst;
}

TEST(removeLeaf) {
  LinkedBST<int, string>* bst = makeExampleBST();
  bst->remove(3);
  bst->checkInvariants();
  CHECK_EQUAL(bst->getSize(), 6);
  CHECK_EQUAL(bst->contains(3), false);
  delete bst;
}

TEST(removeNodeWithLeftChild) {
  LinkedBST<int, string>* bst = makeExampleBST();
  bst->remove(4);
  bst->checkInvariants();
  CHECK_EQUAL(bst->getSize(), 6);
  CHECK_EQUAL(bst->contains(4), false);
  delete bst;
}

TEST(removeNodeWithRightChild) {
  LinkedBST<int, string>* bst = makeExampleBST();
  bst->remove(7);
  bst->checkInvariants();
  CHECK_EQUAL(bst->getSize(), 6);
  CHECK_EQUAL(bst->contains(7), false);
  delete bst;
}

TEST(removeNodeWithTwoChildren) {
  LinkedBST<int, string>* bst = makeExampleBST();
  bst->remove(2);
  bst->checkInvariants();
  CHECK_EQUAL(bst->getSize(), 6);
  CHECK_EQUAL(bst->contains(2), false);
  CHECK_EQUAL(bst->get(3), "3");
  delete bst;
}

TEST(removeRoot) {
  LinkedBST<int, string>* bst = makeExampleBST();
  bst->remove(6);
  bst->checkInvariants();
  CHECK_EQUAL(bst->getSize(), 6);
  CHECK_EQUAL(bst->contains(6), false);
  CHECK_EQUAL(bst->get(7), "7");
  delete bst;
}

TEST(removeInsertRemove) {
  LinkedBST<int, string>* bst = makeExampleBST();
  bst->remove(6);
  bst->checkInvariants();
  CHECK_EQUAL(bst->getSize(), 6);
  CHECK_EQUAL(bst->contains(6), false);
  CHECK_EQUAL(bst->get(7), "7");

  bst->insert(6, "6");
  bst->checkInvariants();
  CHECK_EQUAL(bst->getSize(), 7);
  CHECK_EQUAL(bst->contains(6), true);

  bst->remove(9);
  bst->checkInvariants();
  CHECK_EQUAL(bst->getSize(), 6);
  CHECK_EQUAL(bst->contains(6), true);
  CHECK_EQUAL(bst->contains(9), false);
  CHECK_EQUAL(bst->get(7), "7");
  CHECK_EQUAL(bst->get(6), "6");
  delete bst;
}

// TODO: The order could change here depending on how you implement getKeys
TEST(exampleGetKeys) {
  LinkedBST<int, string>* bst = makeExampleBST();
  vector<int> traversal = bst->getKeys();

  // build vector containing what we the ordering should be
  vector<int> expected;
  expected.push_back(1);
  expected.push_back(2);
  expected.push_back(3);
  expected.push_back(4);
  expected.push_back(6);
  expected.push_back(7);
  expected.push_back(9);
  REQUIRE CHECK_EQUAL(expected.size(), traversal.size());
  for (int i = 0; i < expected.size(); i++) {
    CHECK_EQUAL(expected[i], traversal[i]);
  }
  delete bst;
}

// TODO: The order could change here depending on how you implement getItems
TEST(exampleGetItems) {
  LinkedBST<int, string>* bst = makeExampleBST();
  vector<pair<int, string>> traversal = bst->getItems();

  // build vector containing what we the ordering should be
  vector<pair<int, string>> expected;
  expected.push_back(pair<int, string>(1, "1"));
  expected.push_back(pair<int, string>(2, "2"));
  expected.push_back(pair<int, string>(3, "3"));
  expected.push_back(pair<int, string>(4, "4"));
  expected.push_back(pair<int, string>(6, "6"));
  expected.push_back(pair<int, string>(7, "7"));
  expected.push_back(pair<int, string>(9, "9"));
  REQUIRE CHECK_EQUAL(expected.size(), traversal.size());
  for (int i = 0; i < expected.size(); i++) {
    CHECK_EQUAL(expected[i].first, traversal[i].first);
    CHECK_EQUAL(expected[i].second, traversal[i].second);
  }
  delete bst;
}

TEST(exampleGetHeight) {
  LinkedBST<int, string>* bst = makeExampleBST();
  CHECK_EQUAL(bst->getHeight(), 3);
  delete bst;
}

TEST(removeThenGetHeight) {
  LinkedBST<int, string>* bst = makeExampleBST();
  CHECK_EQUAL(bst->getHeight(), 3);
  bst->remove(6);
  CHECK_EQUAL(bst->getHeight(), 3);
  bst->remove(3);
  CHECK_EQUAL(bst->getHeight(), 2);
  delete bst;
}

TEST(exampleGetMax) {
  LinkedBST<int, string>* bst = makeExampleBST();
  CHECK_EQUAL(bst->getMaxKey(), 9);
  delete bst;
}

TEST(exampleGetMin) {
  LinkedBST<int, string>* bst = makeExampleBST();
  CHECK_EQUAL(bst->getMinKey(), 1);
  delete bst;
}

TEST(examplePreOrderTraversal) {
    LinkedBST<int, string>* bst = makeExampleBST();
    vector<pair<int, string>> traversal = bst->traversePreOrder();

    // build vector containing what we the ordering should be
    vector<pair<int, string>> expected;
    expected.push_back(pair<int, string>(6, "6"));
    expected.push_back(pair<int, string>(2, "2"));
    expected.push_back(pair<int, string>(1, "1"));
    expected.push_back(pair<int, string>(4, "4"));
    expected.push_back(pair<int, string>(3, "3"));
    expected.push_back(pair<int, string>(7, "7"));
    expected.push_back(pair<int, string>(9, "9"));
    REQUIRE CHECK_EQUAL(expected.size(), traversal.size());
    for (int i = 0; i < expected.size(); i++) {
        CHECK_EQUAL(expected[i].first, traversal[i].first);
        CHECK_EQUAL(expected[i].second, traversal[i].second);
    }
    delete bst;
}

// TODO: test LinkedBST<K,V>::getInOrder
TEST(getInOrder){
  LinkedBST<int, string>* bst = makeExampleBST();
  vector<pair<int, string>> traversal = bst->traverseInOrder();

  // build vector containing what we think the ordering should be
  vector<pair<int, string>> expected;
  expected.push_back(pair<int, string>(1, "1"));
  expected.push_back(pair<int, string>(2, "2"));
  expected.push_back(pair<int, string>(3, "3"));
  expected.push_back(pair<int, string>(4, "4"));
  expected.push_back(pair<int, string>(6, "6"));
  expected.push_back(pair<int, string>(7, "7"));
  expected.push_back(pair<int, string>(9, "9"));
  REQUIRE CHECK_EQUAL(expected.size(), traversal.size());
  for (int i = 0; i < expected.size(); i++) {
    CHECK_EQUAL(expected[i].first, traversal[i].first);
    CHECK_EQUAL(expected[i].second, traversal[i].second);
  }
  delete bst;
}

TEST(postOrderTraversal) {
  LinkedBST<int, string>* bst = makeExampleBST();
  vector<pair<int, string>> traversal = bst->traversePostOrder();

  // build vector containing what we the ordering should be
  vector<pair<int, string>> expected;
  expected.push_back(pair<int, string>(1, "1"));
  expected.push_back(pair<int, string>(3, "3"));
  expected.push_back(pair<int, string>(4, "4"));
  expected.push_back(pair<int, string>(2, "2"));
  expected.push_back(pair<int, string>(9, "9"));
  expected.push_back(pair<int, string>(7, "7"));
  expected.push_back(pair<int, string>(6, "6"));
  REQUIRE CHECK_EQUAL(expected.size(), traversal.size());
  for (int i = 0; i < expected.size(); i++) {
    CHECK_EQUAL(expected[i].first, traversal[i].first);
    CHECK_EQUAL(expected[i].second, traversal[i].second);
  }
  delete bst;
}

TEST(levelOrderTraversal) {
  LinkedBST<int, string>* bst = makeExampleBST();
  vector<pair<int, string>> traversal = bst->traverseLevelOrder();

  // build vector containing what we the ordering should be
  vector<pair<int, string>> expected;
  expected.push_back(pair<int, string>(6, "6"));
  expected.push_back(pair<int, string>(2, "2"));
  expected.push_back(pair<int, string>(7, "7"));
  expected.push_back(pair<int, string>(1, "1"));
  expected.push_back(pair<int, string>(4, "4"));
  expected.push_back(pair<int, string>(9, "9"));
  expected.push_back(pair<int, string>(3, "3"));
  REQUIRE CHECK_EQUAL(expected.size(), traversal.size());
  for (int i = 0; i < expected.size(); i++) {
    CHECK_EQUAL(expected[i].first, traversal[i].first);
    CHECK_EQUAL(expected[i].second, traversal[i].second);
  }
  delete bst;
}

int main() {
  
  /*LinkedBST<int, string>* bst = makeExampleBST();
  //CHECK_EQUAL(bst->getHeight(), 3);
  cout<<bst->getHeight()<<endl;
  bst->remove(6);
  cout<<bst->getHeight()<<endl;
  bst->remove(3);
  cout<<bst->getHeight()<<endl;
  cout<<bst->getMinKey()<<endl;
  cout<<bst->getMaxKey()<<endl;
  if(bst->contains(3)) {cout<<"contains 3"<<endl;}
  if(bst->contains(6)) {cout<<"contains 6"<<endl;}
  if(bst->contains(7)) {cout<<"contains 4"<<endl;}*/
  
  return UnitTest::RunAllTests();
}
