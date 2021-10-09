// 15.Boundary Traversal of binary tree
// Given a Binary Tree, find its Boundary Traversal.
// The traversal should be in the following order:
// 1.Left boundary nodes: defined as the path from the root to the left-most node
// ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree.
// 2.Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
// 3.Reverse right boundary nodes: defined as the path from the right-most node to the root.
// The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left
// subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
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
unordered_map<struct Node *, int> m;
vector<int> leaf;
vector<int> leftBoundary(struct Node *root)
{
    vector<int> v;
    if (root == nullptr)
    {
        return v;
    }
    if (root->left == nullptr)
    {
        v.push_back(root->data);
        return v;
    }
    while (root != nullptr)
    {
        v.push_back(root->data);
        m[root] = 1;
        if (root->left != nullptr)
        {
            root = root->left;
        }
        else if (root->right != nullptr)
        {
            root = root->right;
        }
        else
        {
            root = nullptr;
        }
    }
    return v;
}

vector<int> rightBoundary(struct Node *root)
{
    vector<int> v;
    if (root == nullptr || root->right == nullptr)
    {
        return v;
    }
    root = root->right;
    stack<int> s;
    while (root != nullptr)
    {
        s.push(root->data);
        m[root] = 1;
        if (root->right)
        {
            root = root->right;
        }
        else if (root->left)
        {
            root = root->left;
        }
        else
        {
            root = nullptr;
        }
    }
    while (!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    return v;
}

void leafNode(struct Node *root)
{

    if (root != nullptr)
    {
        leafNode(root->left);
        if (m[root] == 0)
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                leaf.push_back(root->data);
            }
            m[root] = 1;
        }
        // cout << root->data << " ";
        leafNode(root->right);
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
    // root->left->left->left->right = new Node(10);
    // root->left->left->right = new Node(8);

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

    root = new Node(1);
    root->right = new Node(2);
    root->right->right = new Node(3);
    root->right->right->left = new Node(4);
    root->right->right->right = new Node(5);

    vector<int> res;
    vector<int> leftBound = leftBoundary(root);
    vector<int> rightBound = rightBoundary(root);
    leafNode(root);

    cout << "left boundary : ";
    for (auto d : leftBound)
    {
        cout << d << " ";
        res.push_back(d);
    }
    cout << endl;

    cout << "leaf : ";
    for (auto d : leaf)
    {
        cout << d << " ";
        res.push_back(d);
    }
    cout << endl;

    cout << "right boundary : ";
    for (auto d : rightBound)
    {
        cout << d << " ";
        res.push_back(d);
    }
    cout << endl;

    for (auto d : res)
    {
        cout << d << " ";
    }
    cout << endl;

    // while (!leftBound.empty())
    // {
    //     res.push_back(leftBound.front());
    //     leftBound.p
    // }
    return 0;
}
