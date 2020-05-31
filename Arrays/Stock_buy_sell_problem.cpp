#include <bits/stdc++.h>
using namespace std;

int stock(int arr[], int n)
{
    // In this, we are searching for the bottoms and the peaks
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
            profit = profit + (arr[i] - arr[i - 1]);
    }

    return profit;
}

int main()
{
    // We are having an array of prices of the stocks
    int arr[] = {1, 5, 3, 1, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << stock(arr, n);
}
