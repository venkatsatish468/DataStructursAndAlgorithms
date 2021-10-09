// 2.Search in Rotated Sorted Array
// Given the array nums after the rotation and an integer target,
// return the index of target if it is in nums, or -1 if it is not in nums
#include <bits/stdc++.h>
using namespace std;
int findElement(int arr[], int l, int h, int t)
{
    int m = -1;
    while (l <= h)
    {
        m = l + (h - l) / 2;
        if (arr[m] == t)
        {
            return m;
        }
        if (arr[m] > t)
        {
            h = m - 1;
        }
        if (arr[m] < t)
        {
            l = m + 1;
        }
    }
    return -1;
}
int findPiviot(int arr[], int n)
{
    if (arr[0] <= arr[n - 1])
    {
        return n - 1;
    }
    int l = 0, h = n - 1, m = 0;
    while (l <= h)
    {
        m = l + (h - l) / 2;
        if (arr[m] > arr[m + 1])
        {
            return m;
        }
        else if (arr[l] > arr[m])
        {
            h = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return -1;
}
int mainCode(int nums[], int n, int target)
{
    int m = findPiviot(nums, n);
    cout << "pivort : " << m << endl;
    int res;
    res = findElement(nums, 0, m, target);
    if (res == -1)
    {
        res = findElement(nums, m + 1, n - 1, target);
    }
    return res;
}
int main()
{
    int nums[] = {4, 5, 6, 7, 8, 0, 1, 2};
    // int nums[] = {0, 1, 2, 4, 5, 6, 7};
    // int nums[] = {8, 9, 2, 3, 4};
    // int nums[] = {7, 8, 1, 2, 3, 4, 5, 6};

    int n = sizeof(nums) / sizeof(nums[0]);
    int result = mainCode(nums, n, 0);
    cout << "search : " << result << endl;

    // int n = sizeof(arr) / sizeof(arr[0]);
    // int l = 0, h = n - 1, m = -1;
    // while (l <= h)
    // {
    //     m = l + (h - l) / 2;
    //     if (arr[m] > arr[m + 1])
    //     {
    //         break;
    //     }
    //     else if (arr[l] > arr[m])
    //     {
    //         h = m - 1;
    //     }
    //     else
    //     {
    //         l = m + 1;
    //     }
    // }
    // cout << "pivot : " << m << endl;
    return 0;
}