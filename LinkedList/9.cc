// 9.Add two numbers represented by linked lists
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

struct node *addNum(struct node *num1Head, struct node *num2Head)
{
    num1Head = reverseNode(num1Head);
    num2Head = reverseNode(num2Head);
    struct node *num1Curr = num1Head, *num2Curr = num2Head;
    int sum = 0, carry = 0, data = 0;
    struct node *sumHead = nullptr, *sumNext = nullptr;
    while (num1Curr != nullptr && num2Curr != nullptr)
    {
        sum = num1Curr->data + num2Curr->data + carry;
        carry = sum / 10;
        data = sum % 10;
        if (sumHead == nullptr)
        {
            sumHead = new node(data);
            sumNext = sumHead;
        }
        else
        {
            sumNext->next = new node(data);
            sumNext = sumNext->next;
        }
        num1Curr = num1Curr->next;
        num2Curr = num2Curr->next;
    }
    while (num1Curr != nullptr)
    {
        sum = num1Curr->data + carry;
        carry = sum / 10;
        data = sum % 10;
        sumNext->next = new node(data);
        sumNext = sumNext->next;
        num1Curr = num1Curr->next;
    }
    while (num2Curr != nullptr)
    {
        sum = num2Curr->data + carry;
        carry = sum / 10;
        data = sum % 10;
        sumNext->next = new node(data);
        sumNext = sumNext->next;
        num2Curr = num2Curr->next;
    }
    if (carry)
    {
        sumNext->next = new node(carry);
    }
    return reverseNode(sumHead);
}

int main()
{
    struct node *num1Head = nullptr, *num2Head = nullptr, *sumHead = nullptr;
    int N1, N2;
    cout << "enter the size of two numbers : ";
    cin >> N1 >> N2;
    cout << endl;
    num1Head = addNode(N1);
    cout << endl;
    num2Head = addNode(N2);
    cout << "num 1 : ";
    printList(num1Head);
    cout << "num 2 : ";
    printList(num2Head);
    sumHead = addNum(num1Head, num2Head);
    cout << "sum : ";
    printList(sumHead);
    return 0;
}