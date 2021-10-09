// 6.Count and Say
// solution1:recursive
// #include <bits/stdc++.h>
// using namespace std;
// string say(int n)
// {
//     if (n == 1)
//     {
//         return "1";
//     }
// if(n==2){
//     return "11";
// }
//     string temp = say(n - 1);
//     int count = 0;
//     string str = "";
//     for (int i = 0; i < temp.length(); i++)
//     {
//         count++;
//         if (i == temp.length() || temp[i] != temp[i + 1])
//         {
//             str = str + to_string(count) + temp[i];
//             count = 0;
//         }
//     }
//     return str;
// }
// int main()
// {
//     int n = 4;
//     string str = say(n);
//     cout << " count and say : " << n << " is: " << str << endl;
//     return 0;
// }

// solution2:loops