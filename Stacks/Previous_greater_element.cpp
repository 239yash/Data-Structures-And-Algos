#include <bits/stdc++.h>
using namespace std;

void prev_greater(int arr[], int n)
{
    std::stack<int> s;

    // Pushing the first character in stack
    // We know that, There is nothing on the left of first character, so
    // Simply printing -1.
    s.push(arr[0]);
    cout << "-1"
         << " ";

    // Now looping across whole array.
    for (int i = 1; i < n; i++)
    {
        // If the top of the stack is less than upcoming one
        // Then, popping it out.
        while (s.empty() == false && s.top() <= arr[i])
        {
            s.pop();
        }

        // When the loop gets greater than upcoming element.
        int pg = (s.empty()) ? -1 : s.top();
        cout << pg << " ";
        s.push(arr[i]);
    }
}

int main()
{
    int arr[] = {15, 10, 18, 12, 4, 6, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    prev_greater(arr, n);
}
