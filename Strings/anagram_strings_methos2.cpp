# include<bits/stdc++.h>

using namespace std;

bool anagram(string,string);
bool anagram(string a,string b)
{
    if(a.length() != b.length())
    return false;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    for(int i = 0; i<a.length();i++)
    {
        if(a[i] != b[i])
        return false;
    }
    return true;
}


int main()
{
    string a = "aabc";
    string b = "abca";

    if(anagram(a,b))
    cout<<"True";
    else
    cout<<"False";
}
