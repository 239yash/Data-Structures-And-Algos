#include <bits/stdc++.h>
using namespace std;


int main()
{
    int a[] = {12,15,18,2,5,6,8,11};
    int n  = 8;
    
    int start = 0;
    int end = n - 1;
    int mid, prev, next;
    
    while (start <= end)
    {
        if(a[start] <= a[end])
        {
            cout<<(n-start)<<endl;
            return 0;
        }
        
        mid = start + (end - start)/2;
        next = (mid+1)%n;
		prev = (mid-1+n)%n;
        
        if(a[mid] <= a[prev] && a[mid] <= a[next])
        {
            cout<<(n-mid)<<endl;
            return 0;
        }
        
        if(a[start] <= a[mid])
        start = mid + 1;
        
        else if(a[mid] <= a[end])
        end = mid - 1;
        
    }
    
    
    return 0;
}
