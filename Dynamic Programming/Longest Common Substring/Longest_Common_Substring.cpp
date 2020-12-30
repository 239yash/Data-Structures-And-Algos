//https://practice.geeksforgeeks.org/problems/longest-common-substring/0
#include<iostream>
using namespace std;
int memo[102][102];
int main()
 {
	//code
	int t,x,y;
	string s1, s2;
	cin>>t;
	while(t-- > 0)
	{
	    cin>>x>>y;
	    cin>>s1>>s2;
	   // cout<<x<<endl;
	   // cout<<y<<endl;
	   // cout<<s1<<endl;
	   // cout<<s2<<endl;
	    for(int i = 0; i < x+1; i++)
        {
            for(int j = 0; j < y+1; j++)
            {
                if(i == 0 || j == 0)
                    memo[i][j] = 0;
            }
        }
        
        for(int i = 1; i < x+1; i++)
        {
            for(int j = 1; j < y+1; j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    memo[i][j] = 1 + memo[i-1][j-1];
                    // ans++;
                }
                else
                {
                    // res = max(res, ans);
                    // ans = 0;
                    memo[i][j] = 0;
                }
            }
        }
        
        // cout<<memo[x][y]<<endl;
        int maxi = 0;
        for(int i = 0; i < x+1; i++)
        {
            for(int j = 0; j < y+1; j++)
            {
                maxi = max(memo[i][j], maxi);
                cout<<memo[i][j]<<" ";
            }
            cout<<endl;
        }
        
        cout<<maxi<<endl;
        
	}
	return 0;
}
