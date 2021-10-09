// 0.reverse a linked list
// solution1:iterative
// use three pointers prev=null,current=head,next=null;
// 1.next=curr.next;
// 2.curr.next=prev;
// 3.prev=curr;
// 4.curr=next;
// return prev;
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

void printData(struct node *temp)
{
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

struct node *reverseLinkedList(struct node *head)
{
    struct node *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct node *reverseUsingStack(struct node *head)
{
    stack<struct node *> s;
    struct node *temp2;
    temp2 = head;
    while (temp2->next != nullptr)
    {
        s.push(temp2);
        temp2 = temp2->next;
    }
    head = temp2;
    while (!s.empty())
    {
        temp2->next = s.top();
        s.pop();
        temp2 = temp2->next;
    }
    temp2->next = NULL;
    return head;
}

int main()
{
    struct node *head = NULL;
    struct node *temp = NULL;
    int n = 1;
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
    cout << "before reversing : ";
    printData(head);
    //below iterative solution;
    // head = reverseLinkedList(head);

    //below solution using stacks;
    head = reverseUsingStack(head);
    cout << "after reversing : ";
    printData(head);
    return 0;
}