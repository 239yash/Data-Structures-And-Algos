#include <bits/stdc++.h>
using namespace std;
#define null NULL
#define ll long long int
int solve(int arr[], int i, int j);

int t[1001][1001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(null);
    cout.tie(null);
    int arr[] = {40,20,30,10,30};
    int n = sizeof(arr)/sizeof(arr[0]);
    memset(t, -1, sizeof(t));
    int i = 1, j = n-1;
    cout<<solve(arr, i, j);
}

int solve(int arr[], int i, int j)
{
    if(i >= j)
    {
        return 0;
    }
    
    if(t[i][j] != -1)
    {
        return t[i][j];
    }
    else
    {
        int mini = INT_MAX;
        int temp;
        for(int k = i; k < j; k++)
        {
            temp = solve(arr, i, k) + solve(arr, k+1, j) + (arr[i-1] * arr[k] * arr[j]);
            mini = min(mini, temp);
        }

        return t[i][j] =  mini;    
    }
}
