// 3.)Row with max 1s
/*Given a boolean 2D array of n x m dimensions where each row is sorted. 
Find the 0-based index of the first row that has the maximum number of 1's.*/

/*for each row find the number count number of ones and compare with previous number if it is greater
update the previous number and store the index. we find the iterator to first one using upper bound and get the position 
using upper_bonund-vector.begin and we subtract the number of coumns with this value to get the count*/
// 1.First solution
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     vector<vector<int>> arr = {{0, 1, 1, 1}, {0, 0, 1, 1}, {1, 1, 1, 1}, {0, 0, 0, 0}};
//     int row = 0;
//     int j = -1;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         auto up = upper_bound(arr[i].begin(), arr[i].end(), 0);
//         int count = up - arr[i].begin();
//         count = arr[i].size() - count;
//         if (count > row)
//         {
//             row = count;
//             j = i;
//         }
//     }
//     return 0;
// }

//2. second solution:for each row use binary search to find the first occurance using(arr[m]==1&&(arr[m-1]==0||m==0))
// #include <bits/stdc++.h>
// using namespace std;
// int find(vector<int> a, int l, int h, int c)
// {
//     while (l <= h)
//     {
//         int m = l + (h - l) / 2;
//         if (a[m] == 1 && (a[m - 1] == 0 || m == 0))
//         {
//             return c - m;
//         }
//         else if (a[m] == 0)
//         {
//             l = m + 1;
//         }
//         else if (a[m] == 1)
//         {
//             h = m - 1;
//         }
//     }
//     return 0;
// }
// int main()
// {
//     vector<vector<int>> arr = {{0, 1, 1, 1}, {0, 0, 1, 1}, {1, 1, 1, 1}, {0, 0, 0, 0}};
//     int row = 0;
//     int j = -1;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         int count = find(arr[i], 0, arr[i].size() - 1, arr[i].size());
//         if (count > row)
//         {
//             row = count;
//             j = i;
//         }
//     }
//     cout << "row: " << j;
//     return 0;
// }