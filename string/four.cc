// 4.A Program to check if strings are rotations of each other or not
// solution: create a temp variale with concatatination of the base string str1+str1 then check
// whether str2 is a substring of temp since temp contains all possible rotations of str1;
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str1 = "AACD", str2 = "ACD";
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    cout << "string 1 : " << str1 << endl;
    cout << "string 2 : " << str2 << endl;
    if (str1.length() != str2.length())
    {
        cout << "not a rotation" << endl;
        exit(0);
    }
    string temp = str1 + str1;
    if (temp.find(str2) != string::npos)
    {
        cout << "it is a rotation" << endl;
        exit(0);
    }
    else
    {
        cout << "not a rotation" << endl;
    }
    return 0;
}