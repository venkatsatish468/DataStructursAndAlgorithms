// 1).Coin Change
// Given a value N, find the number of ways to make change for N cents,
// if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.

// solution 1:
// to get the total number of ways with repeation or the total number of combnation :
// we create a combination array with size 0 to target and for each coin in coins array we iterate on
// the amount from i=1 to size of combination array i.e target+1 use the if condition and return the c[target]
// but this solution gives the total combinatio including repeatation so we use recursive method;
// int main(){
//   int c[n + 1] = {0};
// c[0] = 1;
// for (int i = 0; i < m; i++)
// {
//     int coin = S[i];
//     for (int j = 1; j < n + 1; j++)
//     {
//         int amount = j;
//         if (amount >= coin)
//         {
//             c[amount] += c[amount - coin];
//         }
//     }
// }
//}

// solution 1.1:
// recursive version of above :
// int count(int S[], int n, int N)
// {
//     // if the total is 0, return 1
//     if (N == 0) {
//         return 1;
//     }

//     // return 0 if total becomes negative
//     if (N < 0) {
//         return 0;
//     }

//     // initialize the total number of ways to 0
//     int result = 0;

//     // do for each coin
//     for (int i = 0; i < n; i++)
//     {
//         // recur to see if total can be reached by including
//         // current coin `S[i]`
//         result += count(S, n, N - S[i]);
//     }

//     // return the total number of ways
//     return result;
// }

// solution 2:
// to get distinct number of ways we first include the coin and call function with target-coin and
// we exclude the coin with coins array size decremented

#include <bits/stdc++.h>
using namespace std;

int count(int S[], int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 0 || m < 0)
    {
        return 0;
    }
    int include = count(S, m, n - S[m]);
    int exclude = count(S, m - 1, n);

    return include + exclude;
}
int main()
{
    // int S[] = {1, 2, 3};
    // int n = 4, m = 3;

    int S[] = {2, 5, 3, 6};
    int n = 10, m = 4;
    int r = count(S, m, n);
    cout << "ways : " << r << endl;
    return 0;
}