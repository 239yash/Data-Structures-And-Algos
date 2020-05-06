# include<bits/stdc++.h>
using namespace std;


void Kth_largest(int arr[], int n, int k)
{
    std::priority_queue<int> pq;
    for( int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    for( int i = 0; i < k - 1; i++)
    {
        pq.pop();
    }

    cout<<pq.top()<<" ";
}

int main()
{
    int arr[] = {3,2,1,5,6,4};
    int n = 6;
    int k = 2;
    Kth_largest(arr,n,k);
}
