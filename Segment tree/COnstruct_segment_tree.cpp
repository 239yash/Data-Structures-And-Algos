#include <bits/stdc++.h> 
using namespace std; 


const int n = 5;
int tree[4*n];
const int arr[5] = {10,20,30,40,50};

int construct_st(int ss, int se, int si)
{
    if(ss == se)
    {
        tree[si] = arr[ss];
        return arr[ss];
    }

    int mid = (ss + se)/2;
    tree[si] = construct_st(ss, mid, 2*si+1) + construct_st(mid+1, se, 2*si+2);
    return tree[si];
}

int main()
{
    for(int i = 0; i < 4*n; i++)
    {
        tree[i] = 0;
    }
    construct_st(0, n-1, 0);

    for(int i = 0; i < 4*n; i++)
    {
        cout<<tree[i]<<" ";
    }

}
