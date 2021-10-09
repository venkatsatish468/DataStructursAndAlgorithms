// 13.Check for Balanced Tree
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

bool balance = true;
int height(struct Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    if (abs(left - right) > 1)
    {
        balance = balance && false;
    }
    else
    {
        balance = balance && true;
    }
    return max(left, right) + 1;
}

// solution for diagonal order traversal:
// 1.use a queue
// 2.get the front element and traversal only to front.right until it is null for each traversal
// print the curr data and if curr.left exists only then push it into the queue
// 3.continue 2 until queue is empty.
void diagonalTraversal(struct Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<struct Node *> q;
    q.push(root);
    while (!q.empty())
    {
        struct Node *curr = q.front();
        q.pop();
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            if (curr->left)
            {
                q.push(curr->left);
            }
            curr = curr->right;
        }
    }
}

int isBalanced(struct Node *root)
{
    int h = height(root);
    return h;
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

    // cout << "height of tree : " << isBalanced(root) << endl;
    // if (balance)
    // {
    //     cout << "balanced" << endl;
    // }
    // else
    // {
    //     cout << "not balanace" << endl;
    // }

    diagonalTraversal(root);
    return 0;
}
