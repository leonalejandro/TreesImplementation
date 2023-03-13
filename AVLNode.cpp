#include "AVLNode.h"
using namespace std;

template< class T >
AVLNode<T>::AVLNode()
{
    this->left = NULL;
    this->rigth = NULL;
    this->height = -1;
}

template< class T >
AVLNode<T>::AVLNode(T val)
{
    *this = AVLNode();
    this->data = val;
    this->height = 0;
}

template< class T >
AVLNode<T>::~AVLNode()
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
int AVLNode<T>::updateHeights(){
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
void AVLNode<T>::setData(T val)
{
    this->data = val;
}

template< class T >
T AVLNode<T>::getData()
{
    return this->data;
}

template< class T >
int AVLNode<T>::getHeight()
{
    return this->height;
}

template< class T >
bool AVLNode<T>::isLeaf()
{
    if(this->left == NULL && this->rigth == NULL){
        return true;
    }
    else{
        return false;
    }
}

template< class T >
void AVLNode<T>::setLeft(AVLNode<T> *left) {
  this->left = left;
}

template< class T >
void AVLNode<T>::setRight(AVLNode<T> *rigth) {
  this->rigth = rigth;
}

template< class T >
AVLNode<T>* AVLNode<T>::insertElement(T data)
{
    AVLNode<T>* result = this;
    if(data > this->data && this->rigth == NULL){
        AVLNode<T> *_node = new AVLNode<T>(data);
        _node->toString();
        this->setRight(_node);
    }
    else if (data < this->data && this->left == NULL){
        AVLNode<T> *_node = new AVLNode<T>(data);
        _node->data = data;
        this->setLeft(_node);
    }
    else if (data > this->data){
        this->rigth = this->rigth->insertElement(data);
    }
    else{
        this->left = this->left->insertElement(data);
    }

    this->updateHeights();
    result = this->balancingTree();
    return result;

}

template< class T >
void AVLNode<T>::preOrder()
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
void AVLNode<T>::inOrder()
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
void AVLNode<T>::posOrder()
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
void AVLNode<T>::toString()
{
    cout<<data<<endl;
}

template< class T >
AVLNode<T>* AVLNode<T>::rigthRotation()
{
    AVLNode<T>* parent = this->left;
    this->left = parent->rigth;
    parent->rigth = this;

    return parent;
}

template< class T >
AVLNode<T>* AVLNode<T>::leftRotation()
{
    AVLNode<T>* parent = this->rigth;
    this->rigth = parent->left;
    parent->left = this;

    return parent;
}

template< class T >
AVLNode<T>* AVLNode<T>::rigthLeftRotation()
{
    this->rigth = this->rigth->rigthRotation();
    return this->leftRotation();
}

template< class T >
AVLNode<T>* AVLNode<T>::leftRigthRotation()
{
    this->left = this->left->leftRotation();
    return this->rigthRotation();
}

template< class T >
AVLNode<T>* AVLNode<T>::balancingTree()
{
    int heightLeft, heightRight;
    int heightLeftChild, heightRightChild;
    AVLNode<T> *nodeResult = this;

    if (this->left != NULL){
        this->left = this->left->balancingTree();
        heightLeft = this->left->height;
    }
    else
    {
        heightLeft = -1;
    }

    if (this->rigth != NULL){
        this->rigth = this->rigth->balancingTree();
        heightRight = this->rigth->height;
    } 
    else
    {
         heightRight = -1;
    }

    if ( heightLeft - heightRight == 2)
    {
        if (this->left->left != NULL)
        {
            heightLeftChild = this->left->left->height;
        }
        else 
        {
            heightLeftChild = -1;
        }

        if(this->left->rigth != NULL)
        {
            heightRightChild = this->left->rigth->height;
        }
        else
        {
            heightRightChild = -1;

        }

        if(heightLeftChild - heightRightChild > 0)
        {
            nodeResult = this->rigthRotation();
            nodeResult->updateHeights();
        }
        else if (heightLeftChild - heightRightChild < 0 )
        {
            nodeResult = this->leftRigthRotation();
            nodeResult->updateHeights();
        } 
    }

    else if ( heightLeft - heightRight == -2)
    {
        if (this->rigth->left != NULL)
        {
            heightLeftChild = this->rigth->left->height;
        }
        else 
        {
            heightLeftChild = -1;
        }

        if(this->rigth->rigth != NULL)
        {
            heightRightChild = this->rigth->rigth->height;
        }
        else
        {
            heightRightChild = -1;

        }

        if(heightLeftChild - heightRightChild < 0)
        {
            nodeResult = this->leftRotation();
            nodeResult->updateHeights();
        }
        else if (heightLeftChild - heightRightChild > 0 )
        {
            nodeResult = this->rigthLeftRotation();
            nodeResult->updateHeights();
        } 
    }
    return nodeResult;
}