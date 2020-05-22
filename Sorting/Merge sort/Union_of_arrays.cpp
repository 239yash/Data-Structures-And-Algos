#include <bits/stdc++.h>
using namespace std;

void union_array(int a[], int b[], int n, int m)
{
    int i = 0;
    int j = 0;

    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {
            cout << a[i] << " ";
            i++;
            j++;
        }
        else
        {
            if (a[i] < b[j])
            {
                cout << a[i] << " ";
                i++;
            }
            else
            {
                if (a[i] > b[j])
                {
                    cout << b[j] << " ";
                    j++;
                }
            }
        }
    }

    while (i < n)
        cout << a[i++] << " ";
    while (j < m)
        cout << b[j++] << " ";
}

int main()
{
    int a[] = {2, 5, 8, 13, 15};
    int b[] = {1, 3, 8, 15, 18, 20, 25};
    union_array(a, b, 5, 7);
}
