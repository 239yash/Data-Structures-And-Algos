#include <bits/stdc++.h>
using namespace std;

void current_lead(int arr[], int n)
{
    std::vector<int> v;
    int curr_lead = arr[n - 1];

    // Vector for storing the result.
    v.push_back(curr_lead);

    // Checking for the current element
    // Whether it is small or greater then current lead
    for (int i = n - 2; i >= 0; i--)
    {
        if (curr_lead < arr[i])
        {
            curr_lead = arr[i];
            v.push_back(curr_lead);
        }
    }

    std::reverse(v.begin(), v.end());
    for (auto i : v)
    {
        cout << i << " ";
    }
}

int main()
{
    int arr[] = {15, 7, 10, 4, 3, 6, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    current_lead(arr, n);
}
