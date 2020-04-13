# include<bits/stdc++.h>

using namespace std;

void left_repeat(string);
void left_repeat(string s)
{
    int count[256] = {0};

    for(int i = 0; i<s.length(); i++)
    {
        count[s[i]] ++;
    }

    for(int i = 0; i<s.length(); i++)
    {
        if(count[s[i]] == 1)
        {
            cout<<s[i];
            return;
        }
    }
    return;
    
}

int main()
{
    string a = "geeksforgeeks";
    left_repeat(a);
}
