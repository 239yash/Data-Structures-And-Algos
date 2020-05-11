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

        if( longest_far < longest_curr)
        {
            longest_far = longest_curr;
        }
        
    }
    return longest_far;
}

int main()
{
    int arr[] = {50, 3, 10, 7, 40, 80};
    int n = 6;
    int res = longest_increasing(arr,n);
    cout<<res;
}

