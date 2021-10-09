#include <bits/stdc++.h>
using namespace std;

void mergeSort(int *arr, int low, int mid, int high)
{
    int temp[high - low + 1];
    int i = low, j = mid + 1, k = 0;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }
    for (int a = low; a <= high; a++)
    {
        arr[a] = temp[a - low];
    }
}

void merge(int *arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge(arr, low, mid);
        merge(arr, mid + 1, high);
        mergeSort(arr, low, mid, high);
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << " befor : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    merge(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}