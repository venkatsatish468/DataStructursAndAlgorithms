// 2.Height of Binary Tree
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

int height(struct Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}

// solution 2:use level order traversal;
// 1.loop until queue is not empty.
// get size of queue run another loop until the size is zero and add all the children of the current queue element
// and pop the element by doing this at any given time the content of the queue is all the elements of the particulat level;
int heightIter(struct Node *root)
{
    queue<struct Node *> q;
    int h = 0;
    q.push(root);
    while (!q.empty())
    {
        h++;
        int nq = q.size();
        while (nq--)
        {
            struct Node *curr = q.front();
            q.pop();
            if (curr->left != nullptr)
            {
                q.push(curr->left);
            }
            if (curr->right != nullptr)
            {
                q.push(curr->right);
            }
        }
    }
    return h;
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
    // root->left->left->left = new Node(7);
    // root->left->left->right = new Node(8);
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
    int h = height(root);
    cout << "height : " << h << endl;
    return 0;
}