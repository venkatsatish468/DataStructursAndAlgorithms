// 4.mirror of a tree
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

void printTreeInOrder(struct Node *root)
{
    if (root != nullptr)
    {
        printTreeInOrder(root->left);
        cout << root->data << " ";
        printTreeInOrder(root->right);
    }
    else
    {
        return;
    }
}

struct Node *createMirror(struct Node *root)
{
    if (root == nullptr)
    {
        return root;
    }
    struct Node *leftTemp = nullptr, *rightTemp = nullptr;
    leftTemp = root->left;
    rightTemp = root->right;
    root->left = rightTemp;
    root->right = leftTemp;
    createMirror(root->left);
    createMirror(root->right);
    return root;
}

int main()
{
    struct Node *root = nullptr, *left = nullptr, *right = nullptr;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(8);

    // root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->right->left = new Node(5);
    // root->right->right = new Node(6);
    // root->right->left->left = new Node(7);
    // root->right->left->left->left = new Node(9);
    // root->right->left->right = new Node(8);

    // root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);

    cout << "before mirror : ";
    printTreeInOrder(root);
    root = createMirror(root);
    cout << endl;
    cout << "after mirror : ";
    printTreeInOrder(root);
    cout << endl;
    return 0;
}