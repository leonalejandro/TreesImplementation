#ifndef __AVLNODE__H__
#define __AVLNODE__H__

#include <iostream>


template<class T>
class AVLNode
{
private:
    T data;
    AVLNode<T> * left;
    AVLNode<T> * rigth;
    int height;
public:
    AVLNode();
    AVLNode(T _data);
    ~AVLNode();
    //updates heigths, return the heigth in that node.
    int updateHeights();
    T getData();
    void setData(T _data);
    int getHeight();
    bool isLeaf();
    void setLeft(AVLNode<T> *left) ;
    void setRight(AVLNode<T> *right);

    AVLNode<T>* insertElement(T _data);
 

    // Traversals
    void preOrder();
    void inOrder();
    void posOrder();

    void toString();

private:
    AVLNode<T>* rigthRotation();
    AVLNode<T>* leftRotation();
    AVLNode<T>* rigthLeftRotation();
    AVLNode<T>* leftRigthRotation();
    AVLNode<T>* balancingTree();
};


#include "AVLNode.cpp"
#endif