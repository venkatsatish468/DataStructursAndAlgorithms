// 14.find middle element in linked list
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

struct node *findMiddle(struct node *head)
{
    struct node *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    struct node *head = nullptr, *temp = nullptr;
    int N;
    cin >> N;
    cout << endl;
    head = addNode(N);
    printList(head);
    temp = findMiddle(head);
    cout << "Middle element : " << temp->data;
    return 0;
}