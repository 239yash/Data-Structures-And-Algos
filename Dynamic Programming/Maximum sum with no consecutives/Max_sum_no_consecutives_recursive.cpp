
# include<bits/stdc++.h>
using namespace std;


int sum_max(int arr[], int n)
{
    if( n == 1)
    {
        return arr[0];
    }

    if( n == 2)
    {
        return max(arr[0], arr[1]);
    }

    return max(sum_max(arr, n -1), sum_max(arr, n - 2) + arr[n-1]);
}

int main()
{
    int arr[] = {10,5,15,20,2,30};
    int n = 6;
    cout<<sum_max(arr,n);
}
