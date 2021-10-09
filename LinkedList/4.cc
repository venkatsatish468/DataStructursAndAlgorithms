// 4.Remove loop in Linked List
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

// solution1:using set if set in alread in list that is the start of the list;
struct node *removeLoop(struct node *head)
{
    struct node *temp = head, *prev = nullptr;
    unordered_set<struct node *> m;
    while (temp != nullptr)
    {
        if (m.find(temp) != m.end())
        {
            cout << "loop detected " << endl;
            prev->next = nullptr;
            return head;
        }
        m.insert(temp);
        prev = temp;
        temp = temp->next;
    }
    return head;
}



int main()
{
    struct node *head = nullptr, *temp = nullptr;
    int N = 4;
    head = addNode(N);
    // head->next->next->next->next = head->next->next;
    head->next->next->next->next = head->next;
    head = removeLoop(head);
    printList(head);
    return 0;
}