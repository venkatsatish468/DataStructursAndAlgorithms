// 1.Value equal to index value
// Given an array Arr of N positive integers. Your task is to
// find the elements whose value is equal to that of its index value.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {15, 3, 45, 12, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == i + 1)
        {
            v.push_back(i + 1);
        }
    }
    for (auto it : v)
    {
        cout << it << endl;
    }
}