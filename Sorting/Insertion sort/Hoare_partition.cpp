#include <bits/stdc++.h>
using namespace std;

int hoare_part(int *arr, int l, int h)
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

int main()
{
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int l = 0;
    int r = 6;
    hoare_part(arr, l, r);
    for (int i = 0; i <= r; i++)
        cout << arr[i] << " ";
}
