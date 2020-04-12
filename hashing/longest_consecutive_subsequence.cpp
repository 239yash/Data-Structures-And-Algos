# include<bits/stdc++.h>
using namespace std;

int contiguous_sub(int*,int);
int contiguous_sub(int arr[], int n)
{
    int length_far = 0;
    int length_curr = 1;

    sort(arr,arr+n);

    for(int i = 0;i<n-1;i++)
    {
        if(arr[i] == arr[i+1] -1)
        {
            length_curr ++;
        }
        else
        {
             if(length_curr > length_far)
             {
                 length_far = length_curr;
                 length_curr = 1;
             }
        }
        
    }
    cout<<length_far;

}


int main()
{
    int arr[] = {8,20,7,30};
    int n = 4;
    contiguous_sub(arr,n);
}
