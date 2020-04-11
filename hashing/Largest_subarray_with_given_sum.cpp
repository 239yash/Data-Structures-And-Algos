# include<bits/stdc++.h>
using namespace std;

int big_sub(int*,int,int);
int big_sub(int arr[], int n,int sum)
{
    int prefix_sum = 0;
    int res = 0;
    std::unordered_map<int, int> m;

    for(int i = 0; i<n ; i++)
    {
        prefix_sum = prefix_sum +arr[i];

        if(prefix_sum == sum){res = i +1;}

        if(m.find(prefix_sum) == m.end())
        m.insert({prefix_sum,i});

        if(m.find(prefix_sum - sum) != m.end())
        res = max(res,i-m[prefix_sum - sum]);

    }
    return res;
}


int main()
{
    int arr[] = {8,3,1,5,-6,6,2,2};
    int n = 8;
    int sum = 4;
    cout<<big_sub(arr,n,sum);
}
