#include <bits/stdc++.h>
using namespace std;
int lomuto_partition(int arr[], int l, int h);

int lomuto_partition(int arr[], int l, int h)
{
    int pivot = arr[h];
    int i = l - 1;

    for (int j = l; j <= h - 1; j++)
    {

        // If the current is smaller than the pivot element, then swapping it.
        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    // Now moving the pivot to the correct position.
    std::swap(arr[i + 1], arr[h]);
    return i + 1;
}

void quick_sort(int arr[], int l, int h)
{
    // Base condition. l should be less than h
    if (l < h)
    {
        // Using Lomuto partition we are placing the pivot(last) element at the correct position.
        int p = lomuto_partition(arr, l, h);
        // After placing the pivot at correct position, Calling the same funtion
        // Recursively for both sub-arrays.
        quick_sort(arr, l, p - 1);
        quick_sort(arr, p + 1, h);
    }
}

int main()
{
    int arr[] = {5, 3, 8, 4, 2, 7, 1, 10};
    int l = 0;
    int r = 7;
    quick_sort(arr, l, r);
    for (int i = 0; i <= r; i++)
        cout << arr[i] << " ";
}
