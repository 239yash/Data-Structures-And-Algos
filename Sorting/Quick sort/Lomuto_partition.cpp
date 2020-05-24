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

int main()
{
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int l = 0;
    int r = 6;
    lomuto_part(arr, l, r);
    for (int i = 0; i <= r; i++)
        cout << arr[i] << " ";
}
