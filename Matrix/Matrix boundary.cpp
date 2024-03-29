// C++ program to print boundary element of
// matrix.
#include <bits/stdc++.h>
using namespace std;



void printBoundary(int a[][4], int m, int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
				cout << a[i][j] << " ";
			else
				cout << " "
					<< " ";
		}
		cout << "\n";
	}
}

// Driver code
int main()
{
	int a[4][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 1, 2, 3, 4 }, { 5, 6, 7, 8 } };
	printBoundary(a, 4, 4);
	return 0;
}
