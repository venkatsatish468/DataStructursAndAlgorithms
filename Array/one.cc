#include <bits/stdc++.h>
using namespace std;
int main()
{
    array<int, 5> arr = {1, 2, 3, 4, 5};
    auto p = minmax_element(arr.begin(), arr.end());
    cout << "minimun : " << *p.first << " maxinum : " << *p.second << endl;
}