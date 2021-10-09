#include <bits/stdc++.h>
using namespace std;
int main()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    // int matrix[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    int r = sizeof(matrix) / sizeof(matrix[0]);
    int c = sizeof(matrix[0]) / sizeof(matrix[0][0]);
    int tp = 0, dw = r - 1, lf = 0, rt = c - 1;
    int dir = 0;
    int arr[r * c];
    int j = -1;
    while (tp <= dw && lf <= rt)
    {
        if (dir == 0)
        {
            for (int i = lf; i <= rt; i++)
            {
                cout << matrix[tp][i] << " ";
                arr[++j] = matrix[tp][i];
            }
            tp = tp + 1;
        }
        else if (dir == 1)
        {
            for (int i = tp; i <= dw; i++)
            {
                cout << matrix[i][rt] << " ";
                arr[++j] = matrix[i][rt];
            }
            rt = rt - 1;
        }
        else if (dir == 2)
        {
            for (int i = rt; i >= lf; i--)
            {
                cout << matrix[dw][i] << " ";
                arr[++j] = matrix[dw][i];
            }
            dw = dw - 1;
        }
        else if (dir == 3)
        {
            for (int i = dw; i >= tp; i--)
            {
                cout << matrix[i][lf] << " ";
                arr[++j] = matrix[i][lf];
            }
            lf = lf + 1;
        }
        dir = (dir + 1) % 4;
    }
    cout << endl;
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}