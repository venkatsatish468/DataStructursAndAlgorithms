#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int size = sizeof(a) / sizeof(a[0]);
    int last = a[size - 1];
    for (int i = size - 1; i >= 1; i--)
    {
        a[i] = a[i - 1];
    }
    a[0] = last;
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}