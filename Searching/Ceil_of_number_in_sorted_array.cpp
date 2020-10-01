/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {1,2,3,4,8,10,10,12,19};
    int n = sizeof(a)/sizeof(a[0]);
    int ceil_number = 20;
    
    int start = 0;
    int end = n - 1;
    int mid;
    int res = -1;
    
    while(start <= end)
    {
        mid = start + (end - start)/2;
        
        if(a[mid] == ceil_number)
        {
            res = ceil_number;
            break;
        }
        else if(a[mid] > ceil_number)
        {
            end = mid - 1;
            res = a[mid];
        }
        else if(a[mid] < ceil_number)
        {
            start = mid + 1;
        }
        
    }
    
    cout<<res<<endl;
    return 0;
}
