#include <bits/stdc++.h>
using namespace std;
int binary_search(int start, int end, int x);

int a[12] = {1, 2, 3, 4, 6, 8, 9, 11, 16, 18, 19, 25};

int binary_search(int start, int end, int x)
{
    int mid = (start + end) / 2;
    if (end >= start)
    {
        if (a[mid] == x)
            return mid;

        if (a[mid] > x)
        {
            end = mid - 1;
            binary_search(start, end, x);
        }

        if (a[mid] < x)
        {
            start = mid + 1;
            binary_search(start, end, x);
        }
    }
    return -1;
}

int infinite_array(int x)
{
    if (a[0] == x)
    {
        return 0;
    }
    int i = 1;

    while (arr[i] < x)
    {
        i = i * 2;
    }

    if (arr[i] == x)
    {
        return i;
    }
    else
    {
        return binary_search(i / 2, i, x);
    }
}

int main()
{
    int x;
    int result = infinite_array(x) if (result == -1)
    {
        cout << "the number not found.";
    }
    else
    {
        cout << "found at index" << result;
    }
    return 0;
}
