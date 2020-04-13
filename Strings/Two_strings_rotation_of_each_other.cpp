# include<bits/stdc++.h>

using namespace std;

bool rotation(string,string);
bool rotation(string a, string b)
{
    if(a.length() != b.length())
    return false;

    a = a+a;

    if(a.find(b) != string::npos)
    return true;
}




int main()
{
    string a = "abcd";
    string b = "cdab";
    if(rotation(a,b))
    cout<<"True";
    else
    cout<<"False";
}
