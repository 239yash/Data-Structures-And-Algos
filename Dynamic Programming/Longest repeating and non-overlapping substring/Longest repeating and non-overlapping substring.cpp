#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t,n;
	int dp[1002][1002];
	cin>>t;
	while(t-- > 0)
	{
	    cin>>n;
	    string s;
	    cin>>s;
	    for(int i = 0; i < n+1; i++)
        {
            for(int j = 0; j < n+1; j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
            }
        }
        
        int maxi = -1;
        int x,y;
        for(int i = 1; i < n+1; i++)
        {
            for(int j = 1; j < n+1; j++)
            {
                if(s[i-1] == s[j-1] && i != j)
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    if(dp[i][j] > maxi)
                    {
                        x = i;
                        y = j;
                        maxi = dp[i][j];
                    }
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
 
	    
	   // cout<<maxi<<endl;
	    
	   // cout<<i<<" "<<j;
	   if(maxi != -1){
	    string ans = "";
	    while(dp[x][y])
	    {
	            ans = ans + s[x-1];
	            x--;
	            y--;
	    }
	    
	    reverse(ans.begin(),ans.end());
	    cout<<ans<<endl;
	   }
	    else
	    cout<<"-1"<<endl;
	}
	return 0;
}
