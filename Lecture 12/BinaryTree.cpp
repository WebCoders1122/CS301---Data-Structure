#include <iostream>
#include "TreeNode.h"
using namespace std;
void insert(Node *, int);
int main()
{
    int numbers[] = {3, 7, 2, 7, 4, 9, 2, 5, 9, 1, 8, 4, 6, 5, 10};
    // creating root node
    Node *root = new Node;
    root->setInfo(numbers[0]);
    // inserting alll other nodes from array
    for (int i = 1; numbers[i] > 0; i++)
    {
        insert(root, numbers[i]);
    };
    return 0;
}

// define insert function
void insert(Node *root, int value)
{
    Node *newNode = new Node;
    newNode->setInfo(value);

    Node *current = root;
    Node *parent = nullptr;

    // Find the correct position to insert
    while (current != nullptr)
    {
        parent = current;

        if (value == current->getInfo())
        {
            cout << "\nDuplicate Value\n";
            delete newNode;
            return;
        }
        else if (value < current->getInfo())
        {
            current = current->getLeft();
        }
        else
        {
            current = current->getRight();
        }
    }

    // Insert the new node at the correct position
    if (value < parent->getInfo())
    {
        parent->setLeft(newNode);
    }
    else
    {
        parent->setRight(newNode);
    }
}