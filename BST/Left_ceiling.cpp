# include<bits/stdc++.h>
using namespace std;


void left_ceiling(int arr[], int n)
{
    cout<<"-1"<<" ";
    std::set<int> s;

    s.insert(arr[0]);
    for(int i = 1; i < n; i++)
    {
        if(s.upper_bound(arr[i]) == s.end())
        {
            cout<<"-1"<<" ";
        }
        else
        {
            auto k = s.upper_bound(arr[i]);
            cout<<*k<<" ";
        }

        s.insert(arr[i]);
        
    }
}


int main()
{
    int arr[] = {2,8,30,15,25,12};
    int n = 6;
    left_ceiling(arr,n);
}
