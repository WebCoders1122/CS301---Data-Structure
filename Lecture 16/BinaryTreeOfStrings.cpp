#include <iostream>
#include "Stack with array.cpp"
#include "Queue for tree.h"
using namespace std;
void insert(Node<int> *, int);
void preorder(Node<int> *);
void inorder(Node<int> *);
void postorder(Node<int> *);
void levelOrder(Node<int> *);
Node<int> *remove(Node<int> *tree, int value);
int main()
{
    int numbers[] = {5, 3, 8, 1, 4, 7, 9, 2, 6, 10, 11, 12, 13, 14, 15};
    // creating root node
    Node<int> *root = new Node<int>;
    root->setInfo(numbers[0]);

    // inserting all other nodes from array
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
    cout << "\nLevel Order: ";
    levelOrder(root);
    cout << "\nRemoving 10: ";
    remove(root, 10);
    cout << "\nLevel Order: ";
    levelOrder(root);
    return 0;
}

// define insert function
void insert(Node<int> *root, int value)
{
    Node<int> *newNode = new Node<int>;
    newNode->setInfo(value);

    Node<int> *q = root;
    Node<int> *p = root;

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
// functions to print the tree with recursion calls
void preorder(Node<int> *treeNode)
{
    if (treeNode != nullptr)
    {
        cout << treeNode->getInfo() << " ";
        preorder(treeNode->getLeft());
        preorder(treeNode->getRight());
    }
};
// void inorder(Node<int> *treeNode)
// {
//     if (treeNode != nullptr)
//     {
//         inorder(treeNode->getLeft());
//         cout << treeNode->getInfo() << " ";
//         inorder(treeNode->getRight());
//     }
// }
void postorder(Node<int> *treeNode)
{
    if (treeNode != nullptr)
    {
        postorder(treeNode->getLeft());
        postorder(treeNode->getRight());
        cout << treeNode->getInfo() << " ";
    }
}
// functions to print the tree without recursion calls
void inorder(Node<int> *treeNode)
{
    Stack stack;
    Node<int> *temp = treeNode;
    // this do while loop will run until the stack is empty and the temp is not nullptr pushing all nodes in the stack
    do
    {
        // this while loop will push all the left nodes in the stack
        while (temp != nullptr)
        {
            stack.push(temp);
            temp = temp->getLeft();
        }
        // this will pop the last node from the stack and print it
        if (!stack.isEmpty())
        {
            temp = stack.pop();
            cout << temp->getInfo() << " ";
            temp = temp->getRight();
        }

    } while (!stack.isEmpty() || temp != nullptr);
}
// level order traversal
void levelOrder(Node<int> *root)
{
    Queue<int> q;
    Node<int> *node = root;
    q.enqueue(node);

    while (!q.isEmpty())
    {
        cout << node->getInfo() << " ";
        node = q.dequeue();
        if (node->getLeft() != nullptr)
        {
            q.enqueue(node->getLeft());
        }
        if (node->getRight() != nullptr)
        {
            q.enqueue(node->getRight());
        }
    }
};

// function to find minimum node in the tree
Node<int> *findMin(Node<int> *tree)
{
    if (tree == nullptr)
    {
        return nullptr;
    }
    else if (tree->getLeft() == nullptr)
    {
        return tree;
    }
    return findMin(tree->getLeft());
};

// function to remove a node from the tree
Node<int> *remove(Node<int> *tree, int value)
{
    if (tree == nullptr)
    {
        return nullptr;
    }
    Node<int> *temp;
    int tempInfo = value - tree->getInfo();
    if (tempInfo < 0)
    {
        temp = remove(tree->getLeft(), value);
        tree->setLeft(temp); // this connectes new root of left subtree to the tree
    }
    else if (tempInfo > 0)
    {
        temp = remove(tree->getRight(), value);
        tree->setRight(temp); // this connectes new root of right subtree to the tree
    }
    else if (tree->getLeft() != nullptr && tree->getRight() != nullptr)
    {
        Node<int> *minNode = findMin(tree->getRight()); // todo: declare this function
        tree->setInfo(minNode->getInfo());
        temp = remove(tree->getRight(), minNode->getInfo()); // it is deleting inorder successor
        tree->setRight(temp);                                // to maintain tree structure
    }
    else
    {
        Node<int> *nodeToDelete = tree;
        if (tree->getLeft() == nullptr)
        {
            tree = tree->getRight();
        }
        else if (tree->getRight() == nullptr)
        {
            tree = tree->getLeft();
        }
        else
        {
            tree = nullptr;
        }
        delete nodeToDelete;
    }
    return tree;
}
