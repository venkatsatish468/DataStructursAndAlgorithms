#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[6] = {1, -2, 3, 4, -5, 6};
    vector<int> nums = {-1, -2, 3, 4, 5};
    // int i = -1;
    // for (int j = 0; i < 6; j++)
    // {
    //     if (arr[j] < 0)
    //     {
    //         i++;
    //         swap(arr[i], arr[j]);
    //     }
    // }
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
        {
            if (i != j)
                swap(nums[i], nums[j]);
            j++;
        }
    }
    for (int k = 0; k < nums.size(); k++)
    {
        cout << nums[k] << " ";
    }
    // cout << endl;
    // int start = 0;
    // int end = nums.size() - 1;
    // while (start <= end)
    // {
    //     if (nums[start] < 0 && nums[end] < 0)
    //     {
    //         start++;
    //     }
    //     else if (nums[start] > 0 && nums[end] < 0)
    //     {
    //         swap(nums[start], nums[end]);
    //         start++;
    //         end--;
    //     }
    //     else if (nums[start] > 0 && nums[end] > 0)
    //     {
    //         end--;
    //     }
    // }
    // for (auto it : nums)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;
}