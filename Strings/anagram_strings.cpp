# include<bits/stdc++.h>
#include<iostream> 
#include<string>
using namespace std;

bool anagram(string,string);
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


int main()
{
    string a = "aabc";
    string b = "abc";

    if(anagram(a,b))
    cout<<"True";
    else
    cout<<"False";
}
