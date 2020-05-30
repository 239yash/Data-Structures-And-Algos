#include <bits/stdc++.h>
using namespace std;
void reverse_fun(int arr[], int low, int high);
void left_rot(int arr[], int n, int d);

void left_rot(int arr[], int n, int d)
{
    reverse_fun(arr, 0, d - 1);
    reverse_fun(arr, d, n - 1);
    reverse_fun(arr, 0, n - 1);
}

void reverse_fun(int arr[], int low, int high)
{
    while (low < high)
    {
        std::swap(arr[low], arr[high]);
        low++;
        high--;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2;

    left_rot(arr, n, d);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
