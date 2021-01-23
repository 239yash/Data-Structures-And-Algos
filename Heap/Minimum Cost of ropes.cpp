#define ll long long
long long minCost(long long arr[], long long n) {
    // Your code here
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(ll i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    
    ll sum = 0;
    ll curr_sum = 0;
    while(pq.size() > 0)
    {
        if(pq.size() == 1)
        {
            return sum;
        }
        
        int i = 2;
        curr_sum = 0;
        while(i > 0)
        {
            curr_sum = curr_sum + pq.top();
            pq.pop();
            i--;
        }
        pq.push(curr_sum);
        sum += curr_sum;
    }
    return sum;
}
