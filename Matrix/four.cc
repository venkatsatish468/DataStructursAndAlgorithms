// 4).Sorted matrix
// Given an NxN matrix Mat. Sort all elements of the matrix.
// 1).Store all the elements of matrix into an array or vector sort the vector and store back it into matrix format.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // vector<vector<int>> Mat = {{10, 20, 30, 40},
    //                            {15, 25, 35, 45},
    //                            {27, 29, 37, 48},
    //                            {32, 33, 39, 50}};
    vector<vector<int>> Mat = {{40, 94, 73, 98, 27},
                               {58, 89, 87, 95, 9},
                               {95, 28, 34, 74, 32},
                               {19, 46, 78, 64, 80},
                               {72, 62, 86, 16, 99}};
    int size = Mat.size();
    vector<int> arr;
    int k = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            arr.push_back(Mat[i][j]);
        }
    }
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            Mat[i][j] = arr[k];
            k = k + 1;
        }
    }
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << Mat[i][j] << " ";
        }
    }
    cout << endl;

    return 0;
}