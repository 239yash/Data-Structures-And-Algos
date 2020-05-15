
# include<bits/stdc++.h>
using namespace std;


int count_bst(int n)
{
    if(n == 0)
    {
        return 1;
    }
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum = sum + (count_bst(i) * count_bst(n-1-i));
    }

    return sum;
}

int main()
{
    int n = 5;
    cout<<count_bst(n);
}
