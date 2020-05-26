#include <bits/stdc++.h>
using namespace std;

// An interval has a start time and end time
struct interval
{
    int start, end;
};

// Compares two intervals according to staring times.
bool compareInterval(interval i1, interval i2)
{
    return (i1.start < i2.start);
}

void merge(interval arr[], int n)
{

    sort(arr, arr + n, compareInterval);
    int res = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i].start <= arr[res].end)
        {
            arr[res].start = min(arr[i].start, arr[res].start);
            arr[res].end = max(arr[res].end, arr[i].end);
        }
        else
        {
            res++;
            arr[res] = arr[i];
        }
    }

    for (int i = 0; i <= res; i++)
    {
        cout << arr[i].start << " " << arr[i].end << endl;
    }
}

int main()
{
    interval arr[] = {{1, 3}, {7, 9}, {2, 4}, {4, 5}, {6, 10}};
    int n = sizeof(arr) / sizeof(arr[0]);

    merge(arr, n);
}
