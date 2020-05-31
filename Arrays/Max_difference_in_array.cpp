#include <bits/stdc++.h>
using namespace std;

int maxi(int arr[], int n)
{
    // We'll maintaing two variables, one to store result
    // Second to store the current minimum.
    int res = arr[1] - arr[0];
    int minval = arr[0];

    for (int i = 1; i < n; i++)
    {
        res = max(res, arr[i] - minval);
        minval = min(arr[i], minval);
    }

    return res;
}

int main()
{
    int arr[] = {2, 3, 10, 6, 4, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << maxi(arr, n);
}
