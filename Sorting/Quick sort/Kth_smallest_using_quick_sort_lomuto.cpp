#include <bits/stdc++.h>
using namespace std;

int lomuto_part(int *arr, int l, int h)
{
    int pivot = arr[h];
    int i = l - 1;
    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[h]);
    return (i + 1);
}

int kth_smallest(int arr[], int n, int k)
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int p = lomuto_part(arr, l, r);
        if (p == k - 1)
        {
            return arr[p];
        }
        else if (p > k - 1)
        {
            r = p - 1;
        }
        else
        {
            l = p + 1;
        }
    }
}

int main()
{
    int arr[] = {5, 3, 8, 4, 2, 7, 1, 10};
    int n = 8;
    int k = 3;
    cout << kth_smallest(arr, n, k);
}
