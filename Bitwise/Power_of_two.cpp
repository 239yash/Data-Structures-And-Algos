#include <bits/stdc++.h>
using namespace std;

void pow_of_two(int n)
{
    if (n == 0)
    {
        cout << "FALSE";
        return;
    }
    else
    {
        if ((n & (n - 1)) == 0)
        {
            cout << "TRUE";
            return;
        }
        else
        {
            cout << "FALSE";
            return;
        }
    }
}

int main()
{
    int n = 8;
    pow_of_two(n);
}
