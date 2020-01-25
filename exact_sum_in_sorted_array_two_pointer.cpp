#include <bits/stdc++.h>
using namespace std;

bool exact_sum(int mat[], int n, int x)
{
    int start = 0;
    int end = n-1;
    while(start != end)
    {
        if(mat[start] + mat[end] == x)
        return true;

        if(mat[start] + mat[end] < x)
        start++;

        if(mat[start] + mat[end] > x)
        end--;
    }
    return false;
}

int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    bool result = exact_sum(a,10,15);
    if(result == true)
    cout<<"pair found";
    else
    cout<<"not found";
    return 0;

}