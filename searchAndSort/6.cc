// 6.Find Missing And Repeating
// Given an unsorted array Arr of size N of positive integers.
// One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.
// solution 1:create a temp array of size n+1 and for each temp[arr[i]] increment if temp[i] is equal to
// zero then missing if greater than 1 repeating
#include <bits/stdc++.h>
using namespace std;
int *findMissing(int *arr, int n)
{
    static int res[2];
    int temp[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        temp[arr[i]]++;
    }
    int repeat = 0, missing = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if (temp[i] > 1)
        {
            repeat = i;
        }
        if (temp[i] == 0)
        {
            missing = i;
        }
    }
    res[0] = repeat;
    res[1] = missing;
    return res;
}
int main()
{
    // int arr[] = {4, 3, 6, 2, 1, 1};
    int arr[] = {3, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    // int *p = findMissing(arr, n);
    // cout << "repeating number : " << p[0] << " missing number : " << p[1] << endl;
    int temp[n + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        temp[arr[i]]++;
    }
    int repeat = -1;
    for (int i = 1; i < n + 1; i++)
    {
        if (temp[i] > (n / 2))
        {
            repeat = i;
        }
    }
    cout << "repeat : " << repeat << endl;
    return 0;
}