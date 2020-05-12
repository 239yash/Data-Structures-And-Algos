 
# include<bits/stdc++.h>
using namespace std;


int edit_dist(string s1, string s2, int m, int n)
{
    if(m == 0)
    return n;

    if(n == 0)
    return m;

    if(s1[m-1] == s2[n-1])
    return(edit_dist(s1, s2, m-1, n-1));
    else
    {
        return (1 + min(edit_dist(s1,s2,m,n-1),
                       min(edit_dist(s1,s2,m-1,n),
                       edit_dist(s1,s2,m-1,n-1))));
    }

}

int main()
{
    string s1 = "SATURDAY";
    string s2 = "SUNDAY";
    int m = 8;
    int n = 6;
    cout<<edit_dist(s1,s2,m,n);
}
