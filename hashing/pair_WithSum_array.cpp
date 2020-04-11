# include<bits/stdc++.h>
using namespace std;
int pair_in(int*,int,int);
int pair_in(int arr[], int n, int x)
{
    std::unordered_set<int> set_a;
    for(int i = 0; i < n;i++)
    {
        set_a.insert(arr[i]);
    }

    for(int i = 0;i<n;i++)
    {
        if(set_a.find(x-arr[i]) != set_a.end())
        {
            return(1);
        }
    }
    return(0);


}

int main()
{
    int arr[] = {3,2,8,15,-8};
    int n = 5;
    int x = 17;
    int res = pair_in(arr,n,x);
    if(res)
    cout<<"True";
    else
    cout<<"False";
    
}
