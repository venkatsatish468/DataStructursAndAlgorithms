// 18.Transform to Sum Tree
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

void levelOrder(struct Node *root)
{
    // if we want to find the vertical length of the tree at any level then it is queue.size().
    queue<struct Node *> q;
    q.push(root);
    while (!q.empty())
    {
        struct Node *curr = q.front();
        if (curr->left)
        {
            q.push(curr->left);
        }
        if (curr->right)
        {
            q.push(curr->right);
        }
        cout << curr->data << " ";
        q.pop();
    }
}

int transformTree(struct Node *&root)
{
    if (root == nullptr)
    {
        return 0;
    }
    // if (root->left == nullptr && root->left == nullptr)
    // {
    //     int data = root->data;
    //     root->data = 0;
    //     return data;
    // }
    int old = root->data;
    int left = transformTree(root->left);
    int right = transformTree(root->right);
    root->data = left + right;
    return left + right + old;
}

int main()
{
    struct Node *root = nullptr, *left = nullptr, *right = nullptr;
    // root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->left->right = new Node(9);
    // root->left->left->left = new Node(7);
    // root->left->left->right = new Node(8);

    root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);
    cout << "before : ";
    levelOrder(root);
    cout << endl;
    transformTree(root);
    cout << "after : ";
    levelOrder(root);
    cout << endl;
    cout << "inorder : ";
    printTreeInOrder(root);
    return 0;
}