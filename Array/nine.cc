#include <bits/stdc++.h>
using namespace std;
int main()
{
    // int arr[11] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    // int arr[6] = {1, 4, 3, 2, 6, 7};
    int arr[10] = {2, 3, 1, 1, 2, 4, 2, 0, 1, 1};
    int i = 0,
        c = 0, j = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    while (i < size)
    {
        if (arr[i] == 0 && i < size - 1)
        {
            // return -1;
            j = -1;
            break;
        }
        c = c + arr[i];
        i = i + arr[i];
        if (i >= size - 1)
        {
            // return ++j;
            ++j;
            break;
        }
        j = j + 1;
    }
    if (j == -1)
    {
        cout << "no way" << endl;
    }
    else
    {
        cout << "minimum jumps : " << j << endl;
    }
    return 0;
}