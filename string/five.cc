// 5:Check if the given string is shuffled substring of another string
// Input: str1 = “onetwofour”, str2 = “hellofourtwooneworld”
// Output: YES
// Explanation: str1 is substring in shuffled form of str2 as
// str2 = “hello” + “fourtwoone” + “world”
// str2 = “hello” + str1 + “world”, where str1 = “fourtwoone” (shuffled form)
// Hence, str1 is a substring of str2 in shuffled form.

// Input: str1 = “roseyellow”, str2 = “yellow”
// Output: NO
// Explanation: As the length of str1 is greater than str2. Hence, str1 is not a substring of str2.
// 1.Let n = length of str1, m = length of str2.
// 2.If n > m, then string str1 can never be the substring of str2.
// 3.Else sort the string str1.
// 4.Traverse string str2
//    4.1 Put all the characters of str2 of length n in another string str.
//    4.2 Sort the string str and Compare str and str1.
//    4.3 If str = str1, then string str1 is a shuffled substring of string str2.
//    4.4 else repeat the above process till ith index of str2 such that (i – n + 1 > m) (as after this index the length of remaining string str2 will be less than str1.
// 5. If str is not equals to str1 in above steps, then string str1 can never be substring of str2.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    // string str1 = "geekforgeeks";
    // string str2 = "ekegorfkeegsgeek";
    string A = "abcd";
    string B = "ckabcd";
    int n = A.length();
    int m = B.length();
    // if (n > m)
    // {
    //     cout << " not a suffel" << endl;
    //     exit(0);
    // }
    // sort(str1.begin(), str1.end());
    // int i = 0;
    // while (i + n < m - 1)
    // {
    //     string str = str2.substr(i, n);
    //     sort(str.begin(), str.end());
    //     if (str == str1)
    //     {
    //         cout << "str1 is a suffled substring in str2" << endl;
    //         exit(0);
    //     }
    //     i = i + n;
    // }
    // cout << "not a sub string suffel" << endl;
    if (n > m)
    {
        cout << "false";
    }
    else
    {

        // Sort string A
        sort(A.begin(), A.end());

        // Traverse string B
        for (int i = 0; i < m; i++)
        {

            // Return false if (i+n-1 >= m)
            // doesn't satisfy
            if (i + n - 1 >= m)
                cout << "false" << endl;

            // Initialise the new string
            string str = "";

            // Copy the characters of
            // string B in str till
            // length n
            for (int j = 0; j < n; j++)
                str.push_back(B[i + j]);

            // Sort the string str
            sort(str.begin(), str.end());

            // Return true if sorted
            // string of "str" & sorted
            // string of "A" are equal
            if (str == A)
                cout << "true";
        }
    }
    return 0;
}