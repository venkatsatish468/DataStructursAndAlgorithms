// 1:Palindrome
// Given a string S, check if it is palindrome or not.
// solution1:iterate from last to first store in sepearte string and compare but time o(n);
// solution2:with same time complexity but less space complexity iterate from o to size/2 compare i and size-i-1
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    // char S[5] = "abcd";
    char S[] = "qmoeeomq";
    int re = 0;
    int size = strlen(S);
    for (int i = 0; i < size / 2; i++)
    {
        if (S[i] == S[size - i - 1])
        {
            re = 1;
        }
        else
        {
            re = 0;
        }
    }
    if (re == 1)
    {
        cout << "palandrome " << endl;
    }
    else
    {
        cout << "not palandrome" << endl;
    }
    return 0;
}