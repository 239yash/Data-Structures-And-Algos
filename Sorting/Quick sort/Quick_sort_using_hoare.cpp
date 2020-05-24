#include <bits/stdc++.h>
using namespace std;

int hoare_part(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l - 1;
    int j = h + 1;

    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
        {
            return j;
        }
        std::swap(arr[i], arr[j]);
    }
}

void quic_sort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = hoare_part(arr, l, h);
        quic_sort(arr, l, p);
        quic_sort(arr, p + 1, h);
    }
}

int main()
{
    int arr[] = {5, 3, 8, 4, 2, 7, 1, 10};
    int l = 0;
    int r = 7;
    quic_sort(arr, l, r);
    for (int i = 0; i <= r; i++)
        cout << arr[i] << " ";
}
