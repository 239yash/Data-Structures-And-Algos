 
# include<bits/stdc++.h>
using namespace std;

void LIS(int arr[], int n)
{
    int lis[n];
    lis[0] = 1;
    int res;
    int far;

    for(int i = 1; i < n; i++)
    {
        far = 0;
        for(int j = 0; j < i; j++)
        {
            res = 1;
            if(arr[i] > arr[j])
            {
                res = res + lis[j];
            }

            far = max(far,res);
        }

        lis[i] = far;

    }
    sort(lis, lis+n); 
    cout<<"The largest increasing subsequence is: "<<lis[n-1];


}

int main()
{
    int arr[] = {3,4,2,8,10,5,1};
    int n = 7;
    LIS(arr,n);
}
