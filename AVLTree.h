#ifndef __AVLTREE__H__
#define __AVLTREE__H__

#include <iostream>
#include "AVLNode.h"
#include <utility>

template< class T >
class AVLTree {
  protected:
    AVLNode<T> *root;
  public:
    //constructores
    AVLTree();
    AVLTree(T val);
    //destructor
    ~AVLTree();
    //manipuladores del arbol
    bool isEmpty();
    T getRootData();
    void setRoot(AVLNode<T> *n_root);
    AVLNode<T>* getRoot();
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

#include "AVLTree.cpp"
#endif // __AVLTREE__H__