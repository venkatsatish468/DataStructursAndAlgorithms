// 3.Diameter of Binary Tree
// shows two trees each with diameter nine, the leaves that form the ends of a longest path are shaded
// (note that there is more than one path in each tree of length nine, but no path longer than nine nodes).
#include <bits/stdc++.h>
using namespace std;
int m = INT_MIN;
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

int treeDiameter(struct Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = treeDiameter(root->left);
    int right = treeDiameter(root->right);
    m = max(m, left + right + 1);
    return max(left, right) + 1;
}
int findDiameter(struct Node *root)
{
    int x = treeDiameter(root);
    return m;
}

int main()
{
    struct Node *root = nullptr, *left = nullptr, *right = nullptr;
    root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->right->left = new Node(6);
    // root->left->left->left = new Node(7);
    // root->left->left->right = new Node(8);

    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->left->left = new Node(9);
    root->right->left->right = new Node(8);

    // root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);

    int h = findDiameter(root);
    cout << "diameter : " << h << endl;
    return 0;
}