# include<bits/stdc++.h>
using namespace std;

// Function declaration line, just below this comment.
int longest(string);
int longest(string str)
{
    int n = str.length();
    int res = 0;
    std::vector<int> prev(256,-1);
    int maxEnd;
    int i = 0;

    for(int j = 0; j < n; j++)
    {
        i = max(i, prev[str[j]] + 1);
        maxEnd = j - i + 1;
        res = max(res,maxEnd);
        prev[str[j]] = j;
    }
    cout<<res;
    return res;
}

int main()
{
    string str = "abcadbd";
    longest(str);
}
