// 0.First and last occurrences of x
// Given a sorted array arr containing n elements with possibly duplicate elements,
// the task is to find indexes of first and last occurrences of an element x in the given array.

//solution1:
// create an ordered map and store the occurance of elements then add the occurance until
// we find the search then the count until befor search x is start index and end will be start+x.occurance-1
//but this time complexity is more for maps;
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     // int arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};
//     int arr[] = {1, 3, 5, 5, 5, 5, 7, 123, 125};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int x = 7;
//     map<int, int> m;
//     for (int i = 0; i < n; i++)
//     {
//         m[arr[i]] = m[arr[i]] + 1;
//     }
//     int count = 0;
//     int start, end;
//     for (auto x : m)
//     {
//         cout << x.first << " : " << x.second << endl;
//     }
//     for (auto it : m)
//     {
//         if (it.first == x)
//         {
//             start = count;
//             end = start + it.second - 1;
//             break;
//         }
//         else
//         {
//             count = count + it.second;
//         }
//     }
//     cout << x << " start ind : " << start << " end " << end << endl;
//     return 0;
// }

// solution 2:using upper_bound and lower_bound
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     // int arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};
//     int arr[] = {1, 2, 3, 5, 5, 5, 5, 7, 123, 125};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int x = 2;
//     // vector<int> v;
//     // for (int i = 0; i < n; i++)
//     // {
//     //     v.push_back(arr[i]);
//     // }
//     // vector<int>::iterator lower, upper;
//     // lower = lower_bound(v.begin(), v.end(), x);
//     // upper = upper_bound(v.begin(), v.end(), x);
//     // cout << "start : " << (lower - v.begin()) << " end : " << (upper - v.begin() - 1) << endl;

//     auto lower = lower_bound(begin(arr), end(arr), x);
//     auto upper = upper_bound(begin(arr), end(arr), x);
//     cout << "start : " << (lower - begin(arr)) << " end : " << (upper - begin(arr) - 1) << endl;
//     return 0;
// }

// solution3:using for loop to count the number of time the number has occured
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     // int arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};
//     int arr[] = {1, 3, 5, 5, 5, 5, 7, 123, 125};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int x = 9;
//     int count = 0, p = 0, start;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == x)
//         {
//             count = count + 1;
//             if (p == 0)
//             {
//                 start = i;
//                 p = 1;
//             }
//         }
//     }
//     if (count)
//     {
//         cout << "start : " << start << " end : " << (count + start - 1) << endl;
//     }
//     else
//     {
//         cout << "not found";
//     }
//     return 0;
// }