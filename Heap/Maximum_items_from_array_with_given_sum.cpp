# include<bits/stdc++.h>
using namespace std;

void max_count(int arr[], int sum, int n)
{
    std::priority_queue <int, vector<int>, greater<int> > pq;
    for(int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }

    int sum_curr = 0;
    int count = 0;

    while(pq.empty() == false)
    {
        sum_curr = sum_curr + pq.top();
        pq.pop();

        if(sum >= sum_curr)
        {
            count++;
        }
        else
        {
            cout<<count<<" ";
            break;
        }
        
    }
}

int main()
{
    int arr[] = {20,10,5,30,100};
    max_count(arr,35,5);
}
