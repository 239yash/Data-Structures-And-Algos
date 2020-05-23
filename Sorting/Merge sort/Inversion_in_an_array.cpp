#include <bits/stdc++.h>
using namespace std;
int count_inv(int *arr, int l, int r);
int count_merge(int *arr, int l, int m, int r);

int count_inv(int *arr, int l, int r)
{
    int res = 0;
    if (l < r)
    {
        int m = (l + r) / 2;
        res = res + count_inv(arr, l, m);
        res = res + count_inv(arr, m + 1, r);
        res = res + count_merge(arr, l, m, r);
    }
    return res;
}

int count_merge(int *arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l, res = 0;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
            res = res + (n1 - i);
        }
        k++;
    }

    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    return res;
}

int main()
{
    int arr[] = {2, 4, 1, 3, 5};
    int l = 0;
    int r = 4;
    cout << count_inv(arr, l, r);
}
