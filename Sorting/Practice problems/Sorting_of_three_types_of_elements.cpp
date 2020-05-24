#include <bits/stdc++.h>
using namespace std;

void segregate_three(int *arr, int n)
{
    int l = 0;
    int h = n - 1;
    int mid = 0;

    while (mid <= h)
    {
        // making switch for the array elements
        switch (arr[mid])
        {
        // When the array element is 0.
        case 0:
            std::swap(arr[l], arr[mid]);
            l++;
            mid++;
            break;
        // When the array element is 1.
        case 1:
            mid++;
            break;

        // When the array element is 2.
        case 2:
            std::swap(arr[mid], arr[h]);
            h--;
            break;

        default:
            break;
        }
    }
}

int main()
{
    int arr[] = {0, 2, 1, 2, 1, 0, 1, 2, 1};
    int n = 9;
    segregate_three(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
