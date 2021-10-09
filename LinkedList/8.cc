// 8.Add 1 to a number represented as linked list
// A number N is represented in Linked List such that each digit corresponds to a node in linked list.
// You need to add 1 to it and modify the list.
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
struct node *reverseNode(struct node *head)
{
    struct node *curr = head, *prev = nullptr, *next = nullptr;
    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// soultion 1: get the number in int format add 1 and add all the last digits to a node and reverse the node;
// but this dosent work for large numbers;
struct node *addOne(struct node *head)
{
    struct node *temp = head;
    long long int count = 0;
    while (temp != nullptr)
    {
        count = count * 10 + temp->data;
        temp = temp->next;
    }
    count = count + 1;
    struct node *head2 = nullptr, *temp2 = nullptr;
    int last = 0;
    while (count > 0)
    {
        last = count % 10;
        if (head2 == nullptr)
        {
            head2 = new node(last);
            temp2 = head2;
        }
        else
        {
            temp2->next = new node(last);
            temp2 = temp2->next;
        }
        count = count / 10;
    }
    return reverseNode(head2);
}

// soultion 2 :
struct node *addOne2(struct node *head)
{
    struct node *head2 = reverseNode(head);
    if (head2->data != 9)
    {
        head2->data = head2->data + 1;
        return reverseNode(head2);
    }
    struct node *prev = nullptr, *curr = head2;
    int sum = 0, carry = 0;
    while (curr != nullptr)
    {
        // sum = 0;
        if (prev == nullptr)
        {
            sum = curr->data + 1;
        }
        else
        {
            sum = curr->data + carry;
        }
        carry = sum / 10;
        curr->data = sum % 10;
        prev = curr;
        curr = curr->next;
    }
    if (carry == 1)
    {
        prev->next = new node(1);
    }
    return reverseNode(head2);
}

int main()
{
    struct node *head = nullptr, *temp = nullptr;
    int N = 3;
    head = addNode(N);
    printList(head);
    head = addOne(head);
    printList(head);
    // cout << addOne(head) << endl;
    return 0;
}