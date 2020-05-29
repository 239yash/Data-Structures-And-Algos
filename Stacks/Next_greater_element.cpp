#include <bits/stdc++.h>
using namespace std;

void next_great(int arr[], int n)
{
    // If we dont use vector, then we'll get the output in reverse order.
    std::vector<int> v;
    std::stack<int> s;

    // Pushing the last element in the stack as well as vector.
    s.push(arr[n - 1]);
    v.push_back(-1);

    for (int i = n - 2; i >= 0; i--)
    {
        // Checking for the next greater element for the upcoming element from array
        while (s.empty() == false && s.top() <= arr[i])
        {
            s.pop();
        }

        // Now checking, whether the stack is empty or we've got the next
        //greater element.
        int ng = (s.empty()) ? -1 : s.top();
        v.push_back(ng);
        s.push(arr[i]);
    }

    //Reversing the vector, to get correct output
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {15, 13, 12, 14, 16, 8, 6, 4, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    next_great(arr, n);
}
