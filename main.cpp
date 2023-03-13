#include <iostream>
#include <fstream>
#include <string>
#include <utility>

#include "BinaryTree.h"
#include "BinaryNode.h"
#include "AVLTree.h"


using namespace std;

int main( int argc, char* argv[] ) {
    /*
    cout<<"print1111"<<endl;
    BinaryNode <int> node;
    node.setData(2);
    node.toString();

    BinaryNode <int> node2 ( 5);
    node2.insertElement(7);
    node2.insertElement(6);
    node2.insertElement(4);
    node2.insertElement(-3);
    node2.insertElement(-1);

    cout<<"----------PRE--------"<<endl;
    node2.preOrder();
    cout<<"--------IN--------"<<endl;
    node2.inOrder();
    cout<<"------POS--------"<<endl;
    node2.posOrder();
    cout<<"--------------------"<<endl;
    cout<<"altu:"<<node2.updateHeights();
    */


    /*
    BinaryTree <int> tree (5);
    tree.insert(7);
    tree.insert(6);
    tree.insert(4);
    tree.insert(-3);
    tree.insert(-1);

    cout<<"----------PRE--------"<<endl;
    tree.preOrder();
    cout<<"--------IN--------"<<endl;
    tree.inOrder();
    cout<<"------POS--------"<<endl;
    tree.posOrder();
    cout<<"--------------------"<<endl;
    cout<<"altu:"<<tree.getHeight();
    */

    AVLTree <int> tree (10);
    tree.insert(16);
    tree.insert(5);
    tree.insert(8);
    tree.insert(9);
    tree.insert(15);

    cout<<"----------PRE--------"<<endl;
    tree.preOrder();
    cout<<"--------IN--------"<<endl;
    tree.inOrder();
    cout<<"------POS--------"<<endl;
    tree.posOrder();
    cout<<"--------------------"<<endl;
    cout<<"altu:"<<tree.getHeight();

}