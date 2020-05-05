# include<bits/stdc++.h>
using namespace std;


void k_sorted(int arr[], int n, int k)
{
    std::priority_queue<int, vector<int>, greater<int> > pq;

    for( int i = 0; i <= k; i++)
    {
        pq.push(arr[i]);
    }

    int index = 0;

    for( int i = k+1; i < n; i++)
    {
        arr[index] = pq.top();
        index++;
        pq.pop();
        pq.push(arr[i]);
    }

    while(pq.empty() == false)
    {
        arr[index] = pq.top();
        index++;
        pq.pop();
    }

    for( int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}


int main()
{
    int arr[] = {9,8,7,19,18};
    k_sorted(arr,5,2);
}
