// 3.Detect Loop in linked list
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

// solution1:detectLoop()
// 1.loop from head untill head!=null
// 2.use set to store the address of each node before that check if the
// address already exists if the address of the node already exists then loop exists.
bool detectLoop(struct node *temp)
{
    unordered_set<struct node *> m;
    while (temp != nullptr)
    {
        if (m.find(temp) != m.end())
        {
            return true;
        }
        m.insert(temp);
        temp = temp->next;
    }
    return false;
}

// solution2: Floyd’s Cycle-Finding Algorithm
// 1.use two pointers slow and fast initiall assigned to head
// 2.move slow by one and fast by two positions if there are cycles then at one point they will meet then return false
// until while(slow && fast && fast.next) it slow and fast and fast.next not equal to null;
bool detectLoopFloyd(struct node *head)
{
    struct node *slow = head, *fast = head;
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    struct node *head = nullptr, *temp = nullptr;
    int N = 4;
    head = addNode(N);
    // head->next->next->next->next = head->next->next;
    // if (detectLoop(head))
    // {
    //     cout << "loop detected" << endl;
    // }
    // else
    // {
    //     cout << "no loop" << endl;
    // }
    if (detectLoopFloyd(head))
    {
        cout << "loop detected" << endl;
    }
    else
    {
        cout << "no loop" << endl;
    }
    return 0;
}