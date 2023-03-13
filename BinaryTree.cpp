#include "BinaryTree.h"
#include <iostream>
using namespace std;

template< class T >
BinaryTree<T>::BinaryTree() {
  this->root = NULL;
}

template< class T >
BinaryTree<T>::BinaryTree(T data) {
    BinaryNode <T> * _root = new BinaryNode<T> (data);
    this->root = _root;
}

template< class T >
BinaryTree<T>::~BinaryTree() {
  if (this->root != NULL) {
    delete this->root;
    this->root = NULL;
  }
}

template< class T >
bool BinaryTree<T>::isEmpty() {
  return (this->root == NULL);
}

template< class T >
T BinaryTree<T>::getRootData() {
  return (this->root->data);
}

template< class T >
void BinaryTree<T>::insert(T val) {
    this->root->insertElement(val);
}

template< class T >
void BinaryTree<T>::preOrder() {
    this->root->preOrder();
}

template< class T >
void BinaryTree<T>::inOrder() {
    this->root->preOrder();
}

template< class T >
void BinaryTree<T>::posOrder() {
    this->root->preOrder();
}

template< class T >
int BinaryTree<T>::getHeight(){
    this->root->updateHeights();
}