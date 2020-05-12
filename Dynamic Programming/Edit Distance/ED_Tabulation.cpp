 
# include<bits/stdc++.h>
using namespace std;
int mini( int a, int b, int c);


int edit_dist(string s1, string s2, int m, int n)
{
    int dp[m+1][n+1] = {0};

    for(int i = 0; i <= n; i++)
    {dp[0][i] = i;}

    for(int i = 0; i <= m; i++)
    {dp[i][0] = i;}

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 1 + mini(dp[i][j-1],
                                          dp[i-1][j],
                                          dp[i-1][j-1]);
            }
            
        }
    }
    return dp[m][n];
}

int mini( int a, int b, int c)
{
    if (a <= b && a <= c) 
        return a;
  
    else if (b <= a && b <= c) 
        return b;
  
    else
        return c;
}

int main()
{
    string s1 = "SATURDAY";
    string s2 = "SUNDAY";
    int m = 8;
    int n = 6;
    cout<<edit_dist(s1,s2,m,n);
}
