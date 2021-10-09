// 1.Reverse a Linked List in groups of given size
// Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function)
// in the linked list. If the number of nodes is not a multiple of k then left-out nodes,in the end,
// should be considered as a group and must be reverse

// solution1:recursive
// first use the same reverse using three pointers prev,curr,next
// 1.use while loop curr!=null and count<k by doing this we reverse the first k node
// 2.after the loop end next points to k+1 node and prev to k th node.
// 3.now check if next==null if it is null then we reached to the end of the list and return prev which is the last element
// 4.if next!=null since head points to the first element then after reversing head will become last element of the group
// now call head.nexfunction(next,k); when this function returns the head.next will link to the first element in the next
// reversed group

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

struct node *reverseGroup(struct node *head, int k)
{
    struct node *prev = nullptr, *next = nullptr, *curr = head;
    int count = 0;
    while (curr != nullptr && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next != nullptr)
    {
        head->next = reverseGroup(next, k);
    }
    return prev;
}

int main()
{
    struct node *head = nullptr, *temp = nullptr;
    int n = 5;
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
    cout << "before reverse : ";
    printData(head);
    head = reverseGroup(head, 3);
    cout << "after reversing : ";
    printData(head);
    return 0;
}