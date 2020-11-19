#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "helloworld";
    int n = s.size();
    char x = 'o';
    std::vector<int> a;
    std::vector<int> c;
    
    for(int i = 0; i < n; i++)
    {
        if(s[i] == x)
        {
            c.push_back(i);
        }
    }
    
    if(c.size() == 0)
    {
        cout<<"Khaali hai";
        return 0;
    }
    
    int first = c[0];
    int last = c[c.size() - 1];
    c.push_back(-1);
    
    
    for(int i = 0; i < first; i++)
    {
        a.push_back(first - i);
    }
    
    int check = 0;
    int prev;
    int next;
    
    // for(auto h: a){
    //     cout<<h<<" ";
    // }
    // cout<<endl;
    
    for(int i = first; i < last; i++)
    {
        prev = c[check];
        next = c[check+1];
        
        if(next == -1)
        {
            break;
        }
        
        int mid = int((prev+next)/2);
        if(i == prev){a.push_back(0); continue;}
        if(i == next){a.push_back(0);check++;continue;}
        if(i < mid){a.push_back(i-prev);continue;}
        if(i == mid){a.push_back(min(i-prev, next-i));continue;}
        if(i>mid){a.push_back(next-i);continue;}
    }
    
    // for(auto h: a){
    //     cout<<h<<" ";
    // }
    // cout<<endl;
    
    for(int i = last; i < n; i++)
    {
        a.push_back(i-last);
    }
    
    // for(auto h: a){
    //     cout<<h<<" ";
    // }
    // cout<<endl;
    
    // cout<<n<<endl;
    for(auto h: a){
        cout<<h<<" ";
    }
    return 0;
}






