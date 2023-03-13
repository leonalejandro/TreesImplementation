#include "BinaryNode.h"
using namespace std;

template< class T >
BinaryNode<T>::BinaryNode()
{
    this->left = NULL;
    this->rigth = NULL;
    this->height = -1;
}

template< class T >
BinaryNode<T>::BinaryNode(T val)
{
    *this = BinaryNode();
    this->data = val;
    this->height = 0;
}

template< class T >
BinaryNode<T>::~BinaryNode()
{
    if (this->left != NULL){
        delete this->left;
        this->left = NULL;
    }
    if (this->rigth != NULL){
        delete this->rigth;
        this->rigth = NULL;
    }
}

template< class T >
int BinaryNode<T>::updateHeights(){
    // Case base
    int heighLeft = 0, heightRigth = 0;

    if(this->isLeaf()){
        this->height = 0;
        return 0;
    }
    if(this->left != NULL){
        heighLeft = this->left->updateHeights();
    }
    if(this->rigth != NULL){
        heightRigth = this->rigth->updateHeights();
    }
    if(heighLeft > heightRigth){
        this->height = heighLeft + 1;
    }
    else {
        this->height = heightRigth + 1;
    }
    return this->height;
}

template< class T >
void BinaryNode<T>::setData(T val)
{
    this->data = val;
}

template< class T >
T BinaryNode<T>::getData()
{
    return this->data;
}

template< class T >
int BinaryNode<T>::getHeight()
{
    return this->height;
}

template< class T >
bool BinaryNode<T>::isLeaf()
{
    if(this->left == NULL && this->rigth == NULL){
        return true;
    }
    else{
        return false;
    }
}

template< class T >
void BinaryNode<T>::setLeft(BinaryNode<T> *left) {
  this->left = left;
}

template< class T >
void BinaryNode<T>::setRight(BinaryNode<T> *rigth) {
  this->rigth = rigth;
}

template< class T >
void BinaryNode<T>::insertElement(T data)
{
    if(data > this->data && this->rigth == NULL){
        BinaryNode<T> *_node = new BinaryNode<T>(data);
        _node->toString();
        this->setRight(_node);
    }
    else if (data < this->data && this->left == NULL){
        BinaryNode<T> *_node = new BinaryNode<T>(data);
        _node->data = data;
        this->setLeft(_node);
    }
    else if (data > this->data){
        this->rigth->insertElement(data);
    }
    else{
        this->left->insertElement(data);
    }

}

template< class T >
void BinaryNode<T>::preOrder()
{
    cout<<this->data<<endl;
    if(this->left != NULL){
        this->left->preOrder();
    }
    if(this->rigth != NULL){
        this->rigth->preOrder();
    } 
}

template< class T >
void BinaryNode<T>::inOrder()
{
    if(this->left != NULL){
        this->left->inOrder();
    }
    cout<<this->data<<endl;
    if(this->rigth != NULL){
        this->rigth->inOrder();
    } 
}

template< class T >
void BinaryNode<T>::posOrder()
{
    if(this->left != NULL){
        this->left->posOrder();
    }
    if(this->rigth != NULL){
        this->rigth->posOrder();
    }
    cout<<this->data<<endl;
}

template< class T >
void BinaryNode<T>::toString()
{
    cout<<data<<endl;
}


