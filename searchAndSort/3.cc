// Count Squares
// Consider a sample space S consisting of all perfect squares starting from 1, 4, 9 and so on.
// You are given a number N, you have to output the number of integers less than N in the sample space S.

// solution 1:loop from i=1 to sqrt(n) find if i*i<n then increment count;
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 16;
    int sq = 0, count = 0;
    for (int i = 1; i < sqrt(n); i++)
    {
        if (i * i < n)
        {
            cout << i << " ";
            count++;
        }
    }
    cout << endl;
    cout << "count : " << count << endl;
    return 0;
}