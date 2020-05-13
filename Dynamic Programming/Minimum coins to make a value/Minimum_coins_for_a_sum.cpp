
# include<bits/stdc++.h>
using namespace std;


int getmin(int arr[], int n, int val)
{
    int dp[val+1];
    dp[0] = 0;

    for(int i = 1; i <= val; i++)
    {
        dp[i] = INT_MAX;
    }

    for(int i = 1; i <= val; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(arr[j] <= i)
            {
                int res = dp[i - arr[j]];
                dp[i] = min(dp[i], res+1);
            }
        }
    }

    return dp[val];
}

int main()
{
    int arr[] = {3,4,1};
    cout<<getmin(arr,3,5);
}
