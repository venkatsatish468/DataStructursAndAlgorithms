// 0.Level order traversal
// Given a binary tree, find its level order traversal.
// Level order traversal of a tree is breadth-first traversal for the tree.
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

void printTreePreOrder(struct Node *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        printTreePreOrder(root->left);
        printTreePreOrder(root->right);
    }
    else
    {
        return;
    }
}

void printTreePostOrder(struct Node *root)
{
    if (root != nullptr)
    {
        printTreePostOrder(root->left);
        printTreePostOrder(root->right);
        cout << root->data << " ";
    }
    else
    {
        return;
    }
}

void inOrderRec(struct Node *root)
{
    struct Node *curr = root;
    stack<struct Node *> s;
    s.push(curr);
    curr = curr->left;
    while (!s.empty() || curr != nullptr)
    {
        if (curr != nullptr)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = s.top();
            cout << curr->data << " ";
            s.pop();
            curr = curr->right;
        }
    }
}

void preOrderRec(struct Node *root)
{
    struct Node *curr = root;
    stack<struct Node *> s;
    while (!s.empty() || curr != nullptr)
    {
        if (curr != nullptr)
        {
            cout << curr->data << " ";
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = s.top();
            s.pop();
            curr = curr->right;
        }
    }
}

void PostOrderRec(struct Node *root)
{
    struct Node *curr = root;
    stack<struct Node *> s;
    stack<int> out;
    s.push(root);
    while (!s.empty())
    {
        struct Node *curr = s.top();
        s.pop();
        out.push(curr->data);
        if (curr->left)
        {
            s.push(curr->left);
        }
        if (curr->right)
        {
            s.push(curr->right);
        }
    }
    while (!out.empty())
    {
        cout << out.top() << " ";
        out.pop();
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

void revreseLevelOrder(struct Node *root)
{
    queue<struct Node *> q;
    stack<int> s;
    q.push(root);
    while (!q.empty())
    {
        struct Node *curr = q.front();
        if (curr->right != nullptr)
        {
            q.push(curr->right);
        }
        if (curr->left != nullptr)
        {
            q.push(curr->left);
        }
        q.pop();
        s.push(curr->data);
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
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

    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->right->left = new Node(5);
    // root->right->right = new Node(6);
    // root->right->left->left = new Node(7);
    // root->right->left->right = new Node(8);

    // printTreeInOrder(root);
    // printTreePreOrder(root);
    // printTreePostOrder(root);
    // inOrderRec(root);
    // preOrderRec(root);
    // PostOrderRec(root);
    // levelOrder(root);
    revreseLevelOrder(root);
    return 0;
}