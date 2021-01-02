#include <bits/stdc++.h>
using namespace std;
int shortestCommonSupersequence(string, string, int x, int y);

int main() {
    string x;
    string y;
    cin>>x>>y;
    shortestCommonSupersequence(x,y,x.length(),y.length());
    return 0;
}

int shortestCommonSupersequence(string s1, string s2, int x, int y) {
    //code here
    
    // cout<<s1<<" "<<s2;
    int memo[101][101];
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
            }
            else
            {
                memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
    }
    
    int i = x;
    int j = y;
    string s = "";
    while(i > 0 && j > 0)
    {
        if(s1[i-1] == s2[j-1])
        {
            s += s1[i-1];
            i--;
            j--;
        }
        else
        {
            if(memo[i][j-1] > memo[i-1][j])
            {
                // s += s1[i-1];
                s += s2[j-1];
                j--;
            }
            else
            {
                s += s1[i-1];
                // s += s2[j-1];
                i--;
            }
        }
    }
    if(i <= 0 && j >= 0)
    {
        s += s2[j-1];
        j--;
    }
    else
    {
        if(j <= 0 && i >= 0)
        {
            s += s1[i-1];
            i--;
        }
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    
    return 0;
}


// Relate this problem with Print LCS. Include common character only once
// as we do in Printing LCS and un-common characters as it is, so that
// we can get a SCS.
