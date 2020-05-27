
#include <bits/stdc++.h>
using namespace std;

int a[7] = {1, 2, 2, 3, 3, 3, 3};

int left_search(int start, int end, int x)
{
    int mid;
    while (true)
    {
        int mid = (start + end) / 2;

        // Initializing res = end + 1, to get correct result.
        int res = end + 1;


        // If the a[mid] is x then also we'll go in left to 
        // search for the repeating element.
        if (a[mid] == x)
        {
            end = mid - 1;

            // Updating res, accordingly.
            res = min(res, mid);
        }
        else
        {
            // If the x is greater than a[mid], then going right side
            // Else going in left side.
            if (a[mid] < x)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }


        // If start becomes equal or greater than end. Terminating th function.
        if (start >= end)
        {
            return res;
        }
    }
    return -1;
}

int main()
{
    int result = left_search(0, 6, 3);
    if (result == -1)
    {
        cout << "the number not found.";
    }
    else
    {
        cout << "found at index " << result;
    }
    return 0;
}
