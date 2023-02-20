#include "avl.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <stdexcept>
#include <array>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;

//lets construct the tree shall we
AVL :: AVL() {root = NULL;}


int AVL::getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}
int AVL::getBalance(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}
Node* AVL::rightRotate(Node* node) {
    Node* left = node->left;
    Node* right = left->right;
    left->right = node;
    node->left = right;
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    left->height = max(getHeight(left->left), getHeight(left->right)) + 1;
    return left;
}
Node* AVL::leftRotate(Node* node) {
    Node* right = node->right;
    Node* left = right->left;
    right->left = node;
    node->right = left;
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    right->height = max(getHeight(right->left), getHeight(right->right)) + 1;
    return right;
}


Node* AVL::insert(Node* node, string key) {
    if (node == nullptr) {
        return new Node(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    else {
        return node;
    }
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}


int AVL::search(string a, string b, Node* root_me){
  int counter = 0;
  return search_me(counter, a, b, root_me);
}

int AVL::search_me(int &counter, string a, string b, Node*start){
  if (start==NULL) {return 0;}
  if (a == start->key || b == start->key){
    counter++;
    // cout<<counter<<endl;
  }
  else if((start->key.compare(a)>0)&&(start->key.compare(b)<0)){
    counter++;
    // cout<<counter<<endl;
  }
  search_me(counter, a, b, start->left);
  search_me(counter, a, b, start->right);
  return counter;

}


void AVL::Preorder(Node*start){
  if(start==NULL) return;
  cout<<start->key<<endl;
  Preorder(start->left);
  Preorder(start->right); 
}


