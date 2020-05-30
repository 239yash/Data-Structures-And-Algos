#include <bits/stdc++.h>
using namespace std;
int count_duplicates(int arr[], int n);

// Function for removing the duplicates
void remove_duplicates(int arr[], int n)
{
    // Computing the new size of the array.
    int new_size = count_duplicates(arr, n);

    int distinct_array[new_size];
    distinct_array[0] = arr[0];
    int index = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] != distinct_array[index])
        {
            index++;
            distinct_array[index] = arr[i];
        }
    }

    for (int i = 0; i < new_size; i++)
    {
        cout << distinct_array[i] << " ";
    }
}

int count_duplicates(int arr[], int n)
{
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] != arr[i])
        {
            count++;
        }
    }

    return count;
}

int main()
{
    int arr[] = {10, 20, 30, 30, 30, 30, 40, 50, 50, 60};
    int n = sizeof(arr) / sizeof(arr[0]);

    remove_duplicates(arr, n);
}
