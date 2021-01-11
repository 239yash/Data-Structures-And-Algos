#include<bits/stdc++.h>
#define ll long long
using namespace std;
void mergeSort(ll arr[], ll l, ll r);
void merge(ll arr[], ll l, ll m, ll r);
int main()
{
    ll t,n,m;
    cin>>t;
    while(t-- > 0)
    {
        cin>>n;
        ll arr[n];
        for(ll i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        cin>>m;
        
        mergeSort(arr, 0, n-1);
        // for(ll i = 0; i < n; i++)
        // {
        //     cout<<arr[i]<<" ";
        // }cout<<endl;
        if(m == n)
        {
            cout<<arr[n-1]-arr[0]<<endl;
            continue;
        }
        ll i;
        // for(ll i = 0; i < n; i++)
        // {
        //     cout<<arr[i]<<" ";
        // }cout<<endl;
        ll ans = arr[m-1] - arr[0];
        for(i = m; i < n; i++)
        {
            if((arr[i] - arr[i-m+1]) < ans)
            {
                ans = min(ans, arr[i] - arr[i-m+1]);
                // cout<<ans<<" ";
            }
            // else
            // {
            //     break;
            // }
        }
        // cout<<endl;
        cout<<ans<<endl;
    }
    return 0;
}

void merge(ll arr[], ll l, ll m, ll r)
{
    ll n1 = m - l + 1;
    ll n2 = r - m;
    ll left[n1], right[n2];

    for (ll i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (ll i = 0; i < n2; i++)
        right[i] = arr[m + 1 + i];

    ll i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
}

void mergeSort(ll arr[], ll l, ll r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        ll m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
