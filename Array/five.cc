#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    set<int> arr1(nums1.begin(), nums1.end());
    set<int> arr2(nums2.begin(), nums2.end());
    vector<int> u;
    vector<int>::iterator it1;
    it1 = set_union(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), u.begin());
    for (auto it : u)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << "size : " << u.size();
}
