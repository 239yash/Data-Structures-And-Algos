#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define null NULL
ll count_odd(ll l, ll r);
int func(int **a, int n, int i, int j, int c2, int c3);
int getCount(int l, int r, int p) ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(null);
    cout.tie(null);
    int n;
    cin>>n;
    
    int **a;
    a = new int *[n];
    for(int i = 0; i < n; i++)
        a[i] = new int[n];
        
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin>>a[i][j];
    
    cout<<func(a, n, 0, 0, 0, 0);
	return 0;
}

int func(int **a, int n, int i, int j, int c2, int c3)
{
    if(i >= n || j >= n)
    return 0;
    
    // cout<<a[i][j];
    c2 = c2 + getCount(a[i][j], a[i][j], 2);
    c3 = c3 + getCount(a[i][j], a[i][j], 3);
    // cout<<c2<<" "<<c3;
    
    int extra = min(c2, c3);
    // cout<<extra;
    c2 = c2 - extra;
    c3 = c3 - extra;
    // cout<<c2<<" "<<c3;
    
    if(i+1 >= n)
    return extra + func(a, n, i, j+1, c2, c3);
    if(j+1 >= n)
    return extra + func(a, n, i+1, j, c2, c3);
    
    return extra + min(func(a, n, i+1, j, c2, c3), func(a, n, i, j+1, c2, c3));
}

ll count_odd(ll l, ll r)
{
    ll o = (r - l) / 2; 
	if (r % 2 != 0 || l % 2 != 0) 
		o++; 
	return o; 
}


int getCount(int l, int r, int p) 
{ 
	int cnt = 0; 
	int val = p; 
	while (1) 
	{ 
		int a = r / val; 
		int b = (l - 1) / val; 
		val *= p; 
		if (a - b)
		{ 
			cnt += (a - b); 
		} 
		else
			break; 
	} 
	return cnt; 
} 
