# include<bits/stdc++.h>

using namespace std;
void permute(string,string);
bool anagram(string,string);

void permute(string a, string b)
{
    int nb = b.length();
    int na = a.length();

    for(int i = 0; i < na-nb+1 ; i++)
    {
        if(anagram(a.substr(i,nb),b))
        {
            cout<<"Yes";
            return;
        }
    }
    cout<<"No";
    return;

}

//This is for checking the strings, whether they are anagram or not.
bool anagram(string a,string b)
{
    int count[256] = {0};

    if(a.length() != b.length())
    return false;

    for(int i = 0; i < a.length(); i++)
    count[a[i]] ++;
    for(int i = 0; i < b.length(); i++)
    count[b[i]]--;

    for(int i = 0;i<256;i++)
    {
    if(count[i] != 0)
    return false;}

    return true;
}

//this solution works in O(n^2).
int main()
{
    string a = "geeksforgeeks";
    string b = "gsk";
    permute(a,b);
}
