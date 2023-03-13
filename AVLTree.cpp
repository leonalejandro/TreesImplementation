#include "AVLTree.h"
#include <iostream>
using namespace std;

template< class T >
AVLTree<T>::AVLTree() {
  this->root = NULL;
}

template< class T >
AVLTree<T>::AVLTree(T data) {
    AVLNode <T> * _root = new AVLNode<T> (data);
    this->root = _root;
}

template< class T >
AVLTree<T>::~AVLTree() {
  if (this->root != NULL) {
    delete this->root;
    this->root = NULL;
  }
}

template< class T >
bool AVLTree<T>::isEmpty() {
  return (this->root == NULL);
}

template< class T >
T AVLTree<T>::getRootData() {
  return (this->root->data);
}

template< class T >
void AVLTree<T>::insert(T val) {
    this->root = this->root->insertElement(val);
}

template< class T >
void AVLTree<T>::preOrder() {
    this->root->preOrder();
}

template< class T >
void AVLTree<T>::inOrder() {
    this->root->inOrder();
}

template< class T >
void AVLTree<T>::posOrder() {
    this->root->posOrder();
}

template< class T >
int AVLTree<T>::getHeight(){
    this->root->updateHeights();
}