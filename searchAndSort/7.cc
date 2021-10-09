// 7.Majority Element
// Given an array A of N elements. Find the majority element in the array.
// A majority element in an array A of size N is an element that appears more than N/2 times in the array.

// 7.solution:use a map to store frequency and element and check if frequency > n/2;but taking more time
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     // int arr[] = {4, 3, 6, 2, 1, 1};
//     vector<int> nums = {3, 3, 4};
//     unordered_map<int, int> m;
//     for (int i = 0; i < nums.size(); i++)
//     {

//         m[nums[i]]++;
//     }
//     for (auto it : m)
//     {
//         if (it.second > (nums.size() / 2))
//         {
//             return it.first;
//         }
//     }
//     return 0;
// }
// solution 2: moor voting algorithm
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ele, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            ele = arr[i];
        }
        if (ele == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    if (count > 0)
    {
        cout << "majority : " << ele << endl;
    }
    else
    {
        cout << "no majority" << endl;
    }
    return 0;
}