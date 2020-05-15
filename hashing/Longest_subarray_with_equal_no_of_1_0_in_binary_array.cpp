# include<bits/stdc++.h>
using namespace std;

int big_sub(int*,int);
int big_sub(int arr[], int n)
{
    int prefix_sum = 0;
    int res = 0;
    std::unordered_map<int, int> m;
    int sum = 0;
    for (int i =0;i<n;i++)
    {
        if(arr[i] == 0)
        arr[i] = -1;
    }

for(int i =0;i<n;i++)
{
    prefix_sum = prefix_sum +arr[i];
    if(prefix_sum == sum)
    {res = i+1;}
    if(m.find(prefix_sum) == m.end())
    {m.insert({prefix_sum,i});}
    if(m.find(prefix_sum - sum) != m.end())
    {res = max(res, i-m[prefix_sum-sum]);}

}
return res;
}

int main()
{
    int arr[] = {1,0,1,1,1,0,0};
    int n = 7;
    cout<<big_sub(arr,n);
}
