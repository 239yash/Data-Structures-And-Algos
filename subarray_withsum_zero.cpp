# include<bits/stdc++.h>
using namespace std;

bool sub_array(int*,int);
bool sub_array(int arr[],int n)
{
    std::unordered_set<int> s;
    int prefix_sum = 0;

    for(int i = 0; i<n; i++)
    {
        prefix_sum = prefix_sum + arr[i];
        if(s.find(prefix_sum) != s.end())
        return true;
        if(prefix_sum == 0)
        return true;
    }
}

int main()
{
    int arr[] = {1,5,1,2,4};
    int n = 5;
    if(sub_array(arr,n))
    cout<<"True";
    else
    {
        cout<<"False";
    }
    
}
