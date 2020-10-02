/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
    int n = sizeof(a)/sizeof(a[0]);
    int start = 0;
    int search_number = 7;
    int end = 1;
    int mid;
    bool res = false;
    
    while(true)
    {
        if(a[end] < search_number)
        {
            start = end;
            end = end * 2;
        }
        else if(a[end] == search_number)
        {
            res = true;
            cout<<res;
            return 0;
        }
        else
        {
            break;
        }
    }
    
    while(start <= end)
    {
        mid = start + (end - start)/2;
        if(a[mid] == search_number)
        {
            res  = true;
            break;
        }
        else if(a[mid] <= search_number)
        start = mid + 1;
        
        else
        end = mid - 1;
    }
    
    cout<<res;
    return 0;
}
