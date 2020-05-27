#include <bits/stdc++.h>
using namespace std;

bool two_pointer(int arr[], int n, int x)
{

    int start = 0;
    int end = n - 1;

    while (start < end)
    {
        if (arr[start] + arr[end] == x)
        {
            return true;
        }
        else
        {
            if (arr[start] + arr[end] < x)
            {
                start++;
            }
            else
            {
                end--;
            }
        }
    }
    return false;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 33;
    cout << two_pointer(arr, n, x);
}
