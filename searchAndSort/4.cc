// Maximum and minimum of an array using minimum number of comparisons
#include <bits/stdc++.h>
using namespace std;
int *findMinMax(int arr[], int l, int h)
{
    static int ind[2];
    if (l == h)
    {
        ind[0] = arr[l];
        ind[1] = arr[l];
        return ind;
    }
    else if (h == l + 1)
    {
        if (arr[l] > arr[h])
        {
            ind[0] = arr[h];
            ind[1] = arr[l];
            return ind;
        }
        else
        {
            ind[0] = arr[l];
            ind[1] = arr[h];
            return ind;
        }
    }

    int m = (h + l) / 2;
    int *ptl = findMinMax(arr, l, m);
    int *ptr = findMinMax(arr, m + 1, h);
    if (ptl[0] < ptr[0])
    {
        ind[0] = ptl[0];
    }
    else
    {
        ind[0] = ptr[0];
    }
    if (ptl[1] > ptr[1])
    {
        ind[1] = ptl[1];
    }
    else
    {
        ind[1] = ptr[1];
    }
    return ind;
}
int main()
{
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    // int arr[] = {10, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *ptr = findMinMax(arr, 0, n - 1);
    cout << "minimum : " << ptr[0] << " maxinum : " << ptr[1] << endl;
    return 0;
}