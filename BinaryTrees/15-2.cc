// 15.diagonal element
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
vector<int> res;
void leftTraversal(struct Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left)
    {
        res.push_back(root->data);
        cout << root->data << " ";
        leftTraversal(root->left);
    }
    else if (root->right)
    {
        res.push_back(root->data);
        cout << root->data << " ";
        leftTraversal(root->right);
    }
    return;
}
void rightTraversal(struct Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->right)
    {
        rightTraversal(root->right);
        cout << root->data << " ";
        res.push_back(root->data);
    }
    else if (root->left)
    {
        rightTraversal(root->left);
        cout << root->data << " ";
        res.push_back(root->data);
    }
    return;
}

void leafTraversal(struct Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    leafTraversal(root->left);
    if (!(root->left) && !(root->right))
    {
        cout << root->data << " ";
        res.push_back(root->data);
    }
    leafTraversal(root->right);
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
    root->right->left->right = new Node(9);
    root->left->left->left = new Node(7);
    // root->left->left->left->right = new Node(10);
    root->left->left->right = new Node(8);

    // root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->right->right = new Node(7);
    // root->right->left->right = new Node(8);
    // root->right->right->right = new Node(9);

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

    // root = new Node(20);
    // root->left = new Node(8);
    // root->right = new Node(22);
    // root->left->left = new Node(5);
    // root->left->right = new Node(3);
    // root->right->left = new Node(4);
    // root->right->right = new Node(25);
    // root->left->right->left = new Node(10);
    // root->right->left->right = new Node(14);

    // root = new Node(1);
    // root->left = new Node(2);

    // root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->left->left->left = new Node(8);

    // root = new Node(20);
    // root->left = new Node(8);
    // root->left->left = new Node(4);
    // root->left->right = new Node(12);
    // root->left->right->left = new Node(10);
    // root->left->right->right = new Node(14);
    // root->right = new Node(22);
    // root->right->right = new Node(25);

    // root = new Node(1);
    // root->right = new Node(2);
    // root->right->right = new Node(3);
    // root->right->right->left = new Node(4);
    // root->right->right->right = new Node(5);
    cout << root->data << " ";
    res.push_back(root->data);
    leftTraversal(root->left);
    leafTraversal(root->left);
    leafTraversal(root->right);
    rightTraversal(root->right);
    cout << endl;
    cout << "vect : ";
    for (auto d : res)
    {
        cout << d << " ";
    }
    return 0;
}