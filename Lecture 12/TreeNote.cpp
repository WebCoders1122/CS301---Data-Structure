#include <iostream>
using namespace std;
// Tree Node class
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(/* args */)
    {
        data = 0;
        left = nullptr;
        right = nullptr;
    };
    ~Node() {};
};

int main()
{
    return 0;
}
