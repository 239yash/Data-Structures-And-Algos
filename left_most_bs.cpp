#include <bits/stdc++.h>
using namespace std;

int pos = -1;


int left_most(int a[], int start, int end, int x)
{
    int mid = (start+end)/2;
    if(start<=end)
    {
    if(a[mid] == x )
    {
        pos = mid;
        end = mid -1;
        left_most(a, start, end, x);
        return pos;
    }

    if(a[mid] < x)
    {
        start = mid + 1;
        left_most(a, start, end, x);
    }

    if(a[mid]>x)
    {
        end = mid -1;
        left_most(a, start, end, x);
    }
    }
    return -1 ;


}

int main()
{
    int mat[11] = {1,2,3,4,5,5,5,5,5,6,7};
    int result = left_most(mat,0,10,5);
    if(result == -1)
    {
        cout<<"number not found";
    }
    else
    {
        cout<<"minimum index is "<<result;
    }
    return 0;
}
