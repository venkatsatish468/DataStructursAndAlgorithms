// 8.leftView
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

vector<int> leftView(struct Node *root)
{
    vector<int> v;
    if (root == nullptr)
    {
        return v;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            struct Node *curr = q.front();
            q.pop();
            if (i == 1)
            {
                v.push_back(curr->data);
            }

            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }
    }
    return v;
}

vector<int> topView(struct Node *root)
{
    vector<int> v;
    if (root == nullptr)
    {
        return v;
    }
    map<int, int> m;
    queue<pair<struct Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        struct Node *curr = q.front().first;
        int h = q.front().second;
        if (!m[h])
        {
            m[h] = curr->data;
        }
        if (curr->left)
        {
            q.push({curr->left, h - 1});
        }
        if (curr->right)
        {
            q.push({curr->right, h + 1});
        }
        q.pop();
    }
    for (auto d : m)
    {
        v.push_back(d.second);
    }
    return v;
}

vector<vector<int>> verticalOrderTraversal(struct Node *root)
{
    vector<vector<int>> v;
    if (root == nullptr)
    {
        return v;
    }
    queue<pair<struct Node *, int>> q;
    map<int, vector<int>> m;
    q.push({root, 0});
    while (!q.empty())
    {
        struct Node *curr = q.front().first;
        int h = q.front().second;
        m[h].push_back(curr->data);
        if (curr->left)
        {
            q.push({curr->left, h - 1});
        }
        if (curr->right)
        {
            q.push({curr->right, h + 1});
        }
        q.pop();
    }
    for (auto d : m)
    {
        v.push_back(d.second);
    }
    return v;
}

vector<int> bottomView(struct Node *root)
{
    vector<int> v;
    if (root == nullptr)
    {
        return v;
    }
    map<int, int> m;
    queue<pair<struct Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        struct Node *curr = q.front().first;
        int h = q.front().second;
        m[h] = curr->data;
        if (curr->left)
        {
            q.push({curr->left, h - 1});
        }
        if (curr->right)
        {
            q.push({curr->right, h + 1});
        }
        q.pop();
    }
    for (auto d : m)
    {
        v.push_back(d.second);
    }
    return v;
}

vector<int> zig(struct Node *root)
{
    vector<int> v;
    if (root == nullptr)
    {
        return v;
    }
    deque<struct Node *> q;
    int l = 1;
    q.push_back(root);
    while (!q.empty())
    {
        struct Node *curr = nullptr;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            if (l % 2 != 0)
            {
                curr = q.front();
                q.pop_front();
                v.push_back(curr->data);
                if (curr->left)
                {
                    q.push_back(curr->left);
                }
                if (curr->right)
                {
                    q.push_back(curr->right);
                }
            }
            else if (l % 2 == 0)
            {
                curr = q.back();
                q.pop_back();
                v.push_back(curr->data);
                if (curr->right)
                {
                    q.push_front(curr->right);
                }
                if (curr->left)
                {
                    q.push_front(curr->left);
                }
            }
        }
        l++;
    }
    return v;
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

    // vector<int> res = topView(root);
    // for (auto d : res)
    // {
    //     cout << d << " ";
    // }
    // cout << endl;

    // vector<vector<int>> res = verticalOrderTraversal(root);
    // for (auto it : res)
    // {
    //     for (auto d : it)
    //     {
    //         cout << d << " ";
    //     }
    //     cout << endl;
    // }

    // vector<int> res = bottomView(root);

    vector<int> res = zig(root);
    for (auto d : res)
    {
        cout << d << " ";
    }

    // deque<int> q;
    // q.push_back(1);
    // q.push_back(2);
    // q.push_back(3);
    // q.push_front(4);
    // for (auto it : q)
    // {
    //     cout << it << " ";
    // }
    cout << endl;
    return 0;
}