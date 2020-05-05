# include<bits/stdc++.h>
using namespace std;

void k_largest_ele( int arr[], int k, int n)
{
    std::priority_queue <int, vector<int>, greater<int> > pq;
    for( int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for(int i = k; i < n; i++)
    {
        if(arr[i] > pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    while (!pq.empty()) 
    { 
        cout << '\t' << pq.top(); 
        pq.pop(); 
    } 
    cout << '\n';
}

int main()
{
    int arr[] = {5,15,10,20,8,25,18};
    k_largest_ele(arr,3,7);

    
}
