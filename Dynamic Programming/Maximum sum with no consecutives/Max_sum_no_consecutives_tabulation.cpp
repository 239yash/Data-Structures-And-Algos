
# include<bits/stdc++.h>
using namespace std;


int sum_max(int arr[], int n)
{
    int dp[n+1];
    
    // If the size of the array is 0
    dp[0] = 0;
    
    //If the size of the array is 1
    dp[1] = arr[0];
    
    // If the size of the array is 2.
    dp[2] = max(arr[0], arr[1]);
  
  
    // If the size of the array is greater than 2.
    for(int i = 3; i <= n; i++)
    {
        // There will be two cases, either we'll be including last element or we'll not be including last element.
        // If we include last one, Then we'll add its value to the sum and call for n-2 array.
        // If we does not include last one, then we'll call for n-1 array.
        dp[i] = max(dp[i-1], dp[i-2] + arr[i-1]);
    }

    return dp[n];
}

int main()
{
    int arr[] = {10,5,15,20,2,30};
    int n = 6;
    cout<<sum_max(arr,n);
}





