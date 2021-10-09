// 7.Longest Palindrome in a String
// 1).Input:
// S = "aaaabbaa"
// Output: aabbaa
// Explanation: The longest Palindromic
// substring is "aabbaa".

// 2).Input:
// S = "abc"
// Output: a
// Explanation: "a", "b" and "c" are the
// longest palindromes with same length.
// The result is the one with the least
// starting index.

// solution 1: use three loops the outer two loops to maintain a pointer and inside loop to find the palandrome.
// here we check for every possible sub string.
// time complexity (n^3)
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     // string S = "aaaabbaa";
//     // string S = "forgeeksskeegfor";
//     // string str = "abc";
//     string S = "ab";
//     int maxSize = 1;
//     int start = 0;
//     int size = S.length();
//     for (int i = 0; i < size; i++)
//     {
//         for (int j = i; j < size; j++)
//         {
//             int flag = 1;
//             for (int k = 0; k < (j - i + 1) / 2; k++)
//             {
//                 if (S[k + i] != S[j - k])
//                 {
//                     flag = 0;
//                 }
//             }
//             if (flag && (j - i + 1) > maxSize)
//             {
//                 start = i;
//                 maxSize = j - i + 1;
//             }
//         }
//     }
//     string str = "";
//     for (int i = start; i <= start + maxSize - 1; i++)
//     {
//         str = str + S[i];
//     }
//     cout << str;
//     cout << "  size: " << maxSize << endl;
//     return 0;
// }

// solution 2:dynamic programming matrix method;
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "aaaabbaa";
    // string S = "aaaabbaa";
    // string S = "forgeeksskeegfor";
    // string str = "abc";
    int start = 0, end = 0;
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
            if (table[i][j] == 1 && (j - i + 1) > end)
            {
                start = i;
                end = j - i + 1;
            }
        }
    }
    string x = "";
    for (int i = start; i <= (end + start - 1); i++)
    {
        x = x + str[i];
    }
    cout << "string : " << x << " size : " << end << endl;
    return 0;
}
