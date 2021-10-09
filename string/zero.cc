// 1.Reverse a string
// Write a function that reverses a string. The input string is given as an array of characters s.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> s = {"a", "b", "c", "d"};
    cout << "before reversing : ";
    for (auto it : s)
    {
        cout << it << " ";
    }
    cout << endl;
    // solution1: using reverse() method;
    // reverse(s.begin(), s.end());

    // solution 2: using two pointers to end and start and swap
    // int start = 0;
    // int end = s.size() - 1;
    // while (start < end)
    // {
    //     swap(s[start], s[end]);
    //     start += 1;
    //     end -= 1;
    // }

    cout << "after reversing : ";
    for (auto it : s)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
