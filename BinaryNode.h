#ifndef __BINARYNODE__H__
#define __BINARYNODE__H__

#include <iostream>


template<class T>
class BinaryNode
{
private:
    T data;
    BinaryNode<T> * left;
    BinaryNode<T> * rigth;
    int height;
public:
    BinaryNode();
    BinaryNode(T _data);
    ~BinaryNode();
    //updates heigths, return the heigth in that node.
    int updateHeights();
    T getData();
    void setData(T _data);
    int getHeight();
    bool isLeaf();
    void setLeft(BinaryNode<T> *left) ;
    void setRight(BinaryNode<T> *right);

    void insertElement(T _data);
 

    // Traversals
    void preOrder();
    void inOrder();
    void posOrder();

    void toString();
};


#include "BinaryNode.cpp"
#endif