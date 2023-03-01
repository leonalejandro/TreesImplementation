#ifndef __GENERALNODE__H__
#define __GENERALNODE__H__

#include <iostream>
#include <list>
#include <utility>

template<class T>
class GeneralNode
{
private:
    T data;
    std::list <GeneralNode<T>* > desc;
public:
    GeneralNode();
    ~GeneralNode();
    T& getData();
    void setData(T& _data);
    void clearDesc();
    void addDesc(T& _data);
    void delDesc(T& _data);
};


#include "GeneralNode.cpp"
#endif