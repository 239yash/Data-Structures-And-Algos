#include <bits/stdc++.h>
using namespace std;

int max_one(int arr[], int n)
{
    int count = 0;
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count++;
        }
        else
        {
            count = 0;
        }

        res = max(res, count);
    }

    return res;
}

int main()
{
    // We are having a binary array.
    int arr[] = {1, 1, 0, 1, 1, 1, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << max_one(arr, n);
}
