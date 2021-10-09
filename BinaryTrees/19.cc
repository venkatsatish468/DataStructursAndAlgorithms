// 19.Construct Tree from Inorder & Preorder
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

int searchInd(int inorder[], int startInd, int endInd, int val)
{
    for (int i = startInd; i <= endInd; i++)
    {
        if (inorder[i] == val)
        {
            return i;
        }
    }
    return -1;
}

int pi = 0;
unordered_map<int, int> m;
struct Node *build(int inorder[], int preorder[], int leftInd, int rightInd)
{
    if (leftInd > rightInd)
    {
        return nullptr;
    }
    struct Node *root = new Node(preorder[pi++]);
    if (leftInd == rightInd)
    {
        return root;
    }
    int dist = m[root->data];
    root->left = build(inorder, preorder, leftInd, dist - 1);
    root->right = build(inorder, preorder, dist + 1, rightInd);
    return root;
}

struct Node *bulidTree(int inorder[], int preorder[], int n)
{
    for (int i = 0; i < n; i++)
    {
        m[inorder[i]] = i;
    }
    struct Node *root = build(inorder, preorder, 0, n - 1);
    return root;
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
    // printTreeInOrder(root);
    // cout << endl;
    // printTreePreOrder(root);
    // int inorder[] = {7, 4, 8, 2, 5, 1, 6, 9, 3};
    // int preorder[] = {1, 2, 4, 7, 8, 5, 3, 6, 9};
    int inorder[] = {3, 1, 4, 0, 5, 2};
    int preorder[] = {0, 1, 3, 4, 2, 5};
    int n = sizeof(inorder) / sizeof(inorder[0]);
    root = bulidTree(inorder, preorder, n);
    cout << "inorder : ";
    printTreeInOrder(root);
    cout << endl;
    cout << "preorder : ";
    printTreePreOrder(root);
    cout << endl;
    cout << "postorder : ";
    printTreePostOrder(root);
    return 0;
}