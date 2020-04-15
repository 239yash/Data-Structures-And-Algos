# include<bits/stdc++.h>
using namespace std;

// Function declaration line, just below this comment.
int longest(string);

int longest(string str)
{
    int n = str.size();
    int res = 0;
    for(int i = 0; i < n; i ++)
    {
        std::vector<bool> visited(256);
        for(int j = i; j < n; j++)
        {
            if(visited[str[j]] == true)
            break;

            else
            {
                res = max(res, j-i+1);
                visited[str[j]] = true;
            }
            
        }
    }
    cout<<res;
    return res;
}


int main()
{
    string str = "abcda";
    longest(str);

}
