/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {1,2,3,4,8,10,10,12,19};
    int n = sizeof(a)/sizeof(a[0]);
    int floor_number = 20;
    
    int start = 0;
    int end = n - 1;
    int mid;
    int res = -1;
    
    while(start <= end)
    {
        mid = start + (end - start)/2;
        
        if(a[mid] == floor_number)
        {
            res = floor_number;
            break;
        }
        else if(a[mid] > floor_number)
        {
            end = mid - 1;
        }
        else if(a[mid] < floor_number)
        {
            start = mid + 1;
            res = a[mid];
        }
        
    }
    
    cout<<res<<endl;
    return 0;
}
