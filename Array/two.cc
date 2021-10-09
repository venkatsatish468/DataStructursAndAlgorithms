#include <bits/stdc++.h>
using namespace std;
int main()
{
    array<int, 6> arr = {1, 2, 3, 4, 5, 5};
    set<int> s;
    for (auto it : arr)
    {
        s.insert(it);
    }
    int n = 2;
    auto it = s.begin();
    for (int i = 0; i < n - 1; i++)
    {
        it++;
    }
    cout << "the " << n << "smallest element : " << *it << endl;
}