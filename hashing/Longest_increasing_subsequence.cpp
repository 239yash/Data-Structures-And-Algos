# include<bits/stdc++.h>
using namespace std;


int longest_increasing( int arr[], int n)
{
    int longest_curr = 1;
    int longest_far = 0;

    for(int i = 0; i < n-1; i++)
    {
        if(arr[i] < arr[i + 1])
        {
            longest_curr ++;
        }
        else
        {
            if( longest_far < longest_curr)
            {
                longest_far = longest_curr;
            }
        }
        
    }
    return longest_far;
}

int main()
{
    int arr[] = {10,9,2,5,3,7,101,18};
    int n = 8;
    int res = longest_increasing(arr,n);
    cout<<res;
}
