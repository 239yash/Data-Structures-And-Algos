#include <bits/stdc++.h>
using namespace std;

void intersection_arrays(int a[], int b[], int n, int m)
{
    int i = 0; 
    int j = 0;

    while(i < n && j < m)
    {
        if(a[i] == b[j])
        {
            cout<<a[i]<<" ";
            i++;
            j++;
        }

        if(a[i] < b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
        
    }

}

int main()
{
    int a[] = {2,5,8,13,15};
    int b[] = {1,3,8,15,18,20,25};
    intersection_arrays(a,b,5,7);
}
