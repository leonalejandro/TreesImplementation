#ifndef __BINARYTREE__H__
#define __BINARYTREE__H__

#include <iostream>
#include "BinaryNode.h"
#include <utility>

template< class T >
class BinaryTree {
  protected:
    BinaryNode<T> *root;
  public:
    //constructores
    BinaryTree();
    BinaryTree(T val);
    //destructor
    ~BinaryTree();
    //manipuladores del arbol
    bool isEmpty();
    T getRootData();
    void setRoot(BinaryNode<T> *n_root);
    BinaryNode<T>* getRoot();
    //operaciones del arbol
    void preOrder();
    void inOrder();
    void posOrder();
    void levelOrder();
    bool find(T val);
    void insert(T val);
    void erase(T val);
    T minimo();
    T maximo();
    int size();
    int getHeight();
};


#include "BinaryTree.cpp"
#endif // __BINARYTREE__H__