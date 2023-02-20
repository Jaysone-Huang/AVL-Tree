#ifndef AVL_H
#define AVL_H

#include <string>

using namespace std;

class Node {
public:
    string key;
    int height;
    Node* left;
    Node* right;
    Node(string value) {
        key = value;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

class AVL{
  private:
    int getHeight(Node*);
    int getBalance(Node*);
    Node* rightRotate(Node*);
    Node* leftRotate(Node*);
  public:
    AVL(); //default constructor set root to null
    Node*root;
    Node* insert(Node*, string);
    int search(string, string, Node*);
    int search_me(int&,string, string, Node*);
    void Preorder(Node*);

};
#endif