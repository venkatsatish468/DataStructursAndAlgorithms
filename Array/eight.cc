#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int arr[5] = {1, 2, 3, -2, 5};
    // int arr[8] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int arr[3] = {-1, -2, -3};
    int n = 3;
    // int maxSum = 0, maxEnd = 0;
    // if (all_of(arr, arr + 3, [](int i) { return i < 0; }))
    // {
    //     cout << " max sum : " << *max_element(arr, arr + 3);
    // }
    // for (auto it : arr)
    // {
    //     maxEnd = maxEnd + it;
    //     if (maxSum < maxEnd)
    //     {
    //         maxSum = maxEnd;
    //     }
    //     if (maxEnd < 0)
    //     {
    //         maxEnd = 0;
    //     }
    // }
    // cout << "Max sum : " << maxSum << endl;
    // return 0;
    int maxSum = 0, maxEnd = 0;
    if (all_of(arr, arr + n, [](int i) { return i < 0; }))
    {
        return *max_element(arr, arr + n);
    }
    for (int i = 0; i < n; i++)
    {
        maxEnd = maxEnd + arr[i];
        if (maxSum < maxEnd)
        {
            maxSum = maxEnd;
        }
        if (maxEnd < 0)
        {
            maxEnd = 0;
        }
    }
    return maxSum;
}