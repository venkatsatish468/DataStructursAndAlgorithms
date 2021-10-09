// 2:Print all the duplicates in the input string
#include <bits/stdc++.h>
using namespace std;
int main()
{
    char str[] = "test string";
    // char str[] = "abcda";
    map<char, int> arr;
    for (int i = 0; i < strlen(str); i++)
    {
        if (!isspace(str[i]))
        {
            arr[str[i]] = arr[str[i]] + 1;
        }
    }
    for (auto it : arr)
    {
        if (it.second > 1)
        {
            cout << it.first << " " << it.second << endl;
        }
    }
    return 0;
}