#include <iostream>
#include "TreeNode.h"
using namespace std;
void insert(Node *, int);
void preorder(Node *);
void inorder(Node *);
void postorder(Node *);
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
    cout << "Preorder: ";
    preorder(root);
    cout << "\nInorder: ";
    inorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    return 0;
}

// define insert function
void insert(Node *root, int value)
{
    Node *newNode = new Node;
    newNode->setInfo(value);

    Node *q = root;
    Node *p = root;

    // Find the correct position to insert
    while (value != (p->getInfo()) && q != nullptr)
    {
        p = q;

        if (value > p->getInfo())
        {
            q = p->getRight();
        }
        else if (value < p->getInfo())
        {
            q = p->getLeft();
        }
    }

    // Insert the new node at the correct position
    if (value == p->getInfo())
    {
        cout << "\nDuplicate Value\n";
        delete newNode;
        return;
    }
    else if (value < p->getInfo())
    {
        p->setLeft(newNode);
    }
    else
    {
        p->setRight(newNode);
    }
};
// functions to print the tree
void preorder(Node *treeNode)
{
    if (treeNode != nullptr)
    {
        cout << treeNode->getInfo() << " ";
        preorder(treeNode->getLeft());
        preorder(treeNode->getRight());
    }
};
void inorder(Node *treeNode)
{
    if (treeNode != nullptr)
    {
        inorder(treeNode->getLeft());
        cout << treeNode->getInfo() << " ";
        inorder(treeNode->getRight());
    }
}
void postorder(Node *treeNode)
{
    if (treeNode != nullptr)
    {
        postorder(treeNode->getLeft());
        postorder(treeNode->getRight());
        cout << treeNode->getInfo() << " ";
    }
}
