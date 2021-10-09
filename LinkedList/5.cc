// 5.Remove duplicate element from sorted Linked List
// Given a singly linked list consisting of N nodes.
// The task is to remove duplicates (nodes with duplicate values) from the given list (if exists).
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
    node(int x)
    {
        data = x;
        next = nullptr;
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

// solution 1:use a unordered set and add all the data
// 1.use two pointers temp and prev and check if data in set then prev.link=temp.link and move temp by one.
// 2.if not there in set add it move prev to temp and temp by on position at last return head.
struct node *removeDuplicate(struct node *head)
{
    unordered_set<int> m;
    struct node *temp = head, *prev = nullptr;
    while (temp != nullptr)
    {
        if (m.find(temp->data) != m.end())
        {
            prev->next = temp->next;
            temp = temp->next;
        }
        else
        {
            m.insert(temp->data);
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}

struct node *removeDuplicate1(struct node *head)
{
    struct node *curr = head, *next = nullptr;
    while (curr->next != nullptr)
    {
        if (curr->data == curr->next->data)
        {
            next = curr->next->next;
            free(curr->next);
            curr->next = next;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

struct node *removeBlock(struct node *head)
{
    struct node *temp = head;
    while (temp->next != nullptr && temp->data == temp->next->data)
    {
        temp = temp->next;
    }
    return temp;
}
struct node *deleteDuplicate(struct node *head)
{
    if (head == nullptr)
        return head;
    struct node *curr = head, *prev = nullptr, *next = nullptr;
    while (curr->next != nullptr || curr != nullptr)
    {
        if (curr->data == curr->next->data)
        {
            next = removeBlock(curr);
            prev->next = next->next;
            curr = next->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

int main()
{
    struct node *head = nullptr, *temp = nullptr;
    int N = 3;
    head = addNode(N);
    printList(head);
    // head = removeDuplicate(head);
    // head = removeDuplicate1(head);
    head = deleteDuplicate(head);
    printList(head);
    return 0;
}