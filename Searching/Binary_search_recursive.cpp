
#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    int result = binary_search(0, 11, 8);
    if (result == -1)
    {
        cout << "the number not found.";
    }
    else
    {
        cout << "found at index" << result;
    }
    return 0;
}
