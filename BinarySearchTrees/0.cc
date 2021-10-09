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

void addNode(struct Node *&root, int data)
{
    if (root == nullptr)
    {
        root = new Node(data);
        return;
    }
    struct Node *temp = root, *prev = nullptr;
    while (temp != nullptr)
    {
        if (temp->data > data)
        {
            prev = temp;
            temp = temp->left;
        }
        else if (temp->data <= data)
        {
            prev = temp;
            temp = temp->right;
        }
    }
    if (prev->data > data)
    {
        prev->left = new Node(data);
        return;
    }
    else if (prev->data <= data)
    {
        prev->right = new Node(data);
        return;
    }
    return;
}

int searchTree(struct Node *root, int data)
{
    int level = 1;
    while (root != nullptr)
    {
        if (root->data == data)
        {
            return level;
        }
        if (root->data > data)
        {
            root = root->left;
            level++;
        }
        else if (root->data <= data)
        {
            root = root->right;
            level++;
        }
    }
    return -1;
}

struct Node *getMin(struct Node *root)
{
    while (root != nullptr && root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

struct Node *deleteNode(struct Node *root, int data)
{
    if (root == nullptr)
    {
        return root;
    }
    if (root->data > data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        else if (root->left == nullptr)
        {
            struct Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            struct Node *temp = root->left;
            delete root;
            return temp;
        }
        struct Node *min = getMin(root->right);
        root->data = min->data;
        root->right = deleteNode(root->right, min->data);
    }
    return root;
}

void findPreSus(struct Node *root, struct Node *&pre, struct Node *&suc, int key)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->data == key)
    {
        if (root->left != nullptr)
        {
            struct Node *temp = root->left;
            while (temp->right != nullptr)
            {
                temp = temp->right;
            }
            pre = temp;
        }
        if (root->right != nullptr)
        {
            struct Node *temp = root->right;
            while (temp->left != nullptr)
            {
                temp = temp->left;
            }
            suc = temp;
        }
        return;
    }
    if (root->data > key)
    {
        suc = root;
        findPreSus(root->left, pre, suc, key);
    }
    else if (root->data <= key)
    {
        pre = root;
        findPreSus(root->right, pre, suc, key);
    }
}

void inorder(struct Node *root, struct Node *&prev, int &f)
{
    if (root != nullptr)
    {
        inorder(root->left, prev, f);
        if (prev != nullptr && (prev->data > root->data))
        {
            f = 0;
        }
        prev = root;
        inorder(root->right, prev, f);
    }
}
bool checkBst(struct Node *root)
{
    // if(root!=nullptr){
    //     check
    // }
    struct Node *prev = nullptr;
    int f = 1;
    inorder(root, prev, f);
    if (f == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    struct Node *root = nullptr, *left = nullptr, *right = nullptr;
    root = new Node(8);
    root->left = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(2);
    root->right = new Node(10);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    // int N = 9;
    // for (int i = 0; i < N; i++)
    // {
    //     int d;
    //     cin >> d;
    //     addNode(root, d);
    // }
    // cout << endl;
    // levelOrder(root);

    // int res = searchTree(root, 20);
    // if (res != -1)
    // {
    //     cout << "found at level : " << res << endl;
    // }
    // else
    // {
    //     cout << "not found" << endl;
    // }
    // printTreeInOrder(root);
    // cout << endl;

    // 2.delete
    // root = deleteNode(root, 2);
    // printTreeInOrder(root);

    //2.  predecessor and successor
    // struct Node *pre, *suc;
    // findPreSus(root, pre, suc, 3);
    // if (pre != nullptr)
    // {
    //     cout << pre->data << " ";
    // }
    // else
    // {
    //     cout << -1 << " ";
    // }
    // if (suc != nullptr)
    // {
    //     cout << suc->data << " ";
    // }
    // else
    // {
    //     cout << -1 << " ";
    // }

    if (checkBst(root) == true)
    {
        cout << "it is bst" << endl;
    }
    else
    {
        cout << "it is not bst" << endl;
    }
    return 0;
}