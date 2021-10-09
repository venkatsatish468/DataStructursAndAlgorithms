// 6.Remove duplicates from an unsorted linked list
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct node *addNode(int n)
{
    struct node *temp = nullptr, *head = nullptr;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        if (i == 0)
        {
            head = new node(data);
            temp = head;
        }
        else
        {
            temp->next = new node(data);
            temp = temp->next;
        }
    }
    return head;
}

void printList(struct node *temp)
{
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

struct node *deleteDuplicate(struct node *head)
{
    unordered_set<int> m;
    struct node *temp = head;
    struct node *head2 = nullptr, *next2 = nullptr;
    while (temp != nullptr)
    {
        if (m.find(temp->data) == m.end())
        {
            m.insert(temp->data);
            if (head2 == nullptr)
            {
                head2 = new node(temp->data);
                next2 = head2;
            }
            else
            {
                next2->next = new node(temp->data);
                next2 = next2->next;
            }
            temp = temp->next;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head2;
}

int main()
{
    struct node *head = nullptr, *temp = nullptr;
    int N = 4;
    head = addNode(N);
    printList(head);
    head = deleteDuplicate(head);
    printList(head);
    return 0;
}