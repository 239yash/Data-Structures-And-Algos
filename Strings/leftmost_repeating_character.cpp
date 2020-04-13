# include<bits/stdc++.h>

using namespace std;

void left_repeat(string);
void left_repeat(string s)
{
    int count[256] = {0};

    for(int i = 0; i<s.length(); i++)
    {
        count[s[i]] ++;
        if(count[s[i]] == 2)
        {
            cout<<s[i];
            return;
        }
    }
    return;
    
}

int main()
{
    string a = "abcdgnh";
    left_repeat(a);
}
