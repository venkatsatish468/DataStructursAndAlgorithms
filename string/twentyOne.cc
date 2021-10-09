// Count Palindromic Subsequences
// Given a string str of length N,
//  you have to find number of palindromic subsequence
//  (need not necessarily be distinct) which could be formed from the string str.
// Input:
// Str = "aab"
// Output:
// 4
// Explanation:
// palindromic subsequence are :"a", "a", "b", "aa"

// solution dynamic programming matrix method;
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "aaaa";
    int count = 0;
    int table[str.length()][str.length()];
    for (int g = 0; g < str.length(); g++)
    {
        for (int i = 0, j = g; j < str.length(); i++, j++)
        {
            if (g == 0)
            {
                table[i][j] = 1;
            }
            else if (g == 1)
            {
                if (str[i] == str[j])
                {
                    table[i][j] = 1;
                }
                else
                {
                    table[i][j] = 0;
                }
            }
            else
            {
                if (str[i] == str[j] && table[i + 1][j - 1] == 1)
                {
                    table[i][j] = 1;
                }
                else
                {
                    table[i][j] = 0;
                }
            }
            if (table[i][j] == 1)
            {
                count = count + 1;
            }
        }
    }
    cout << "total palsubstring : " << count << endl;
    return 0;
}