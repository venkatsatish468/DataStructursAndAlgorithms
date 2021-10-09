// 12.Merge Sort for Linked List
// Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.
// Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node()
    {
    }
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

void printNode(struct Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

struct Node *addNode(int n)
{
    struct Node *temp = nullptr, *head = nullptr;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        if (i == 0)
        {
            head = new Node(data);
            temp = head;
        }
        else
        {
            temp->next = new Node(data);
            temp = temp->next;
        }
    }
    return head;
}

struct Node *findMiddle(struct Node *head)
{
    struct Node *slow = head, *fast = head->next;
    while (slow->next != NULL && (fast != NULL && fast->next != NULL))
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct Node *merging(struct Node *first, struct Node *second)
{
    struct Node *tempHead = nullptr, *tempNext = nullptr;
    while (first != nullptr && second != nullptr)
    {
        if (first->data < second->data)
        {
            if (tempHead == nullptr)
            {
                tempHead = first;
                tempNext = tempHead;
            }
            else
            {
                tempNext->next = first;
                tempNext = tempNext->next;
            }
            first = first->next;
        }
        else
        {
            if (tempHead == nullptr)
            {
                tempHead = second;
                tempNext = tempHead;
            }
            else
            {
                tempNext->next = second;
                tempNext = tempNext->next;
            }
            second = second->next;
        }
    }
    while (first != nullptr)
    {
        tempNext->next = first;
        tempNext = tempNext->next;
        first = first->next;
    }
    while (second != nullptr)
    {
        tempNext->next = second;
        tempNext = tempNext->next;
        second = second->next;
    }
    return tempHead;
}

struct Node *divide(struct Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    struct Node *middle = findMiddle(head);
    struct Node *firstPart = head, *secondPart = middle->next;
    middle->next = nullptr;
    struct Node *finalHead = merging(divide(firstPart), divide(secondPart));
    return finalHead;
}

int main()
{
    struct Node *head = nullptr;
    // struct Node *temp = new Node;
    int N;
    cin >> N;
    cout << endl;
    head = addNode(N);
    printNode(head);
    head = divide(head);
    printNode(head);
    return 0;
}