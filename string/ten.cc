// 10.Given a string S. The task is to print all permutations of a given string.

// solution 1: using stl next_permutations method;
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     // string S = "ABSG";
//     // int count = 0;
//     // vector<string> per;
//     // sort(S.begin(), S.end());
//     // do
//     // {
//     //     cout << S << " ";
//     //     per.push_back(S);
//     //     count++;
//     // } while (next_permutation(S.begin(), S.end()));
//     // cout << endl;
//     // cout << "count : " << count << endl;
//     // cout << "vector size : " << per.size() << endl;
//     // vector<vector<int>> in;
//     // vector<int> num = {1, 2, 3};
//     // in.push_back(num);
//     // return 0;
// }

// solution 2:recursion
// iterate from 0 to length of input at each index take the char get the left and the right substring
// add the left and righ substrings and add the char to output and call the function on remain and new output.
#include <bits/stdc++.h>
using namespace std;
void printPer(string input, string output)
{
    if (input.length() == 0)
    {
        cout << output << " ";
        return;
    }
    for (int i = 0; i < input.length(); i++)
    {
        char ch = input[i];
        string left = input.substr(0, i);
        string right = input.substr(i + 1);
        string rem = left + right;
        printPer(rem, output + ch);
    }
}

int main()
{
    string s = "abc";
    printPer(s, "");
    return 0;
}