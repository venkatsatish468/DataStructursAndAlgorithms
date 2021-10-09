// 16.Construct Binary Tree from String with bracket representation
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
void inOrder(struct Node *root)
{
    if (root != nullptr)
    {
        inOrder(root->left);
        res.push_back(root->data);
        inOrder(root->right);
    }
}

void construtInPlaceDll(struct Node *root, struct Node *&head, struct Node *&prev, int &f)
{
    if (root != nullptr)
    {
        construtInPlaceDll(root->left, head, prev, f);
        if (f == 0)
        {
            head = root;
            prev = root;
            f = 1;
        }
        else
        {
            prev->right = root;
            prev->right->left = prev;
            prev = prev->right;
        }
        construtInPlaceDll(root->right, head, prev, f);
    }
}

struct Node *construtDouble(struct Node *root)
{
    // inOrder(root);
    // struct Node *prev = nullptr, *next = nullptr, *first = nullptr;
    // for (int i = 0; i < res.size(); i++)
    // {
    //     if (i == 0)
    //     {
    //         first = new Node(res[i]);
    //         prev = first;
    //         next = first;
    //     }
    //     else
    //     {
    //         next->right = new Node(res[i]);
    //         next = next->right;
    //         next->left = prev;
    //         prev = prev->right;
    //     }
    // }
    // return first;
    struct Node *head = nullptr, *prev = nullptr;
    int f = 0;
    construtInPlaceDll(root, head, prev, f);
    return head;
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
    root->left->left->right = new Node(8);
    struct Node *result = construtDouble(root);
    while (result != nullptr)
    {
        cout << result->data << " ";
        result = result->right;
    }
    return 0;
}