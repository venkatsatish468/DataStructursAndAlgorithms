#include <bits/stdc++.h>
using namespace std;
template <typename T>
void reverseArray(T array)
{
    // vector<T> array = arr;
    reverse(array.begin(), array.end());
    for (auto it : array)
    {
        cout << it << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    string str = "abcd";
    reverseArray(str);
    return 0;
}