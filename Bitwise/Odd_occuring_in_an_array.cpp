#include <bits/stdc++.h>
using namespace std;

void odd_occuring(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = res ^ arr[i];
    }

    if (res == 0)
    {
        cout << "No odd occuring number";
        return;
    }
    else
    {
        cout << "Odd occuring is " << res;
    }
}

int main()
{
    int arr[] = {3, 4, 4, 4, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    odd_occuring(arr, n);
}
