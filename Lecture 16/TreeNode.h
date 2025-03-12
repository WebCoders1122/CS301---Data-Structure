#ifndef TREE_NODE_H
#define TREE_NODE_H
#include <iostream>
using namespace std;
template <class T>
// Tree Node class
class Node
{
private:
    T data;
    Node *left;
    Node *right;

public:
    Node(/* args */)
    {
        data = 0;
        left = nullptr;
        right = nullptr;
    };
    ~Node() {};
    // utility function
    T getInfo()
    {
        return data;
    }
    Node *getLeft()
    {
        return left;
    }
    Node *getRight()
    {
        return right;
    }
    void setInfo(T val)
    {
        data = val;
    }
    void setLeft(Node *l)
    {
        left = l;
    }
    void setRight(Node *r)
    {
        right = r;
    }
};

#endif // TREE_NODE_H