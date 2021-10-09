#include <bits/stdc++.h>
using namespace std;
int main()
{
    forward_list<int> fl;
    forward_list<int>::iterator it1;
    it1 = fl.begin();
    fl.insert_after(it1, {1});
    it1++;
    fl.insert_after(it1, {2});
    for (auto it : fl)
    {
        cout << it << endl;
    }
    return 0;
}