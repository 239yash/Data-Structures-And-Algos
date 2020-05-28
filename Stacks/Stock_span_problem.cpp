#include <bits/stdc++.h>
using namespace std;

void stock_span(int arr[], int n)
{
    std::stack<int> s;
    s.push(0);
    cout << "1"
         << " ";

    for (int i = 1; i < n; i++)
    {
        while (s.empty() == false && arr[s.top()] <= arr[i])
        {
            s.pop();
        }

        int span = (s.empty()) ? i + 1 : (i - s.top());
        cout << span << " ";
        s.push(i);
    }
}

int main()
{
    int arr[] = {15, 13, 12, 14, 16, 8, 6, 4, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    stock_span(arr, n);
}
