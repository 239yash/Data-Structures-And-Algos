#include <bits/stdc++.h>
using namespace std;

bool is_pair(int,int,int);
int a[10] = {1,2,3,4,5,6,7,8,9,10};

bool triplet_sum(int n, int x)
{
    for(int i=0;i<n;i++)
    {
        bool res = is_pair(i,n-1,x-a[i]);
        if(res == true)
        return true;
    }
    return false;

}

bool is_pair(int start, int end, int sum)
{
    while(start != end)
    {
        if(a[start] + a[end] == sum)
        return true;

        if(a[start] + a[end] < sum)
        start++;

        if(a[start] + a[end] > sum)
        end--;
    }
    return false;
}

int main()
{

    bool result = triplet_sum(10,18);
    if(result == true)
    cout<<"pair found";
    else
    cout<<"not found";
    return 0;
}
