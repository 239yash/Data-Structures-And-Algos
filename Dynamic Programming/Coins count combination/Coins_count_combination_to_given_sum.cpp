#include <bits/stdc++.h>
using namespace std;

int get_count(int coins[], int n, int sum)
{
    int dp[sum + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= sum; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= sum; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j - 1];

            if (coins[j - 1] <= i)
            {
                dp[i][j] = dp[i][j] + dp[i - coins[j - 1]][j];
            }
        }
    }

    // for (int i = 0; i <= sum; i++)
    // {
    //     for (int j = 0; j <= n; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return dp[sum][n];
}

int main()
{
    int coins[] = {1, 2, 3};
    int sum = 4;
    int n = 3;

    cout << get_count(coins, n, sum);
}
