# include<bits/stdc++.h>
using namespace std;
//Function declarations
bool solve();
bool issafe(int i, int j, int c);





const int n = 9;
int grid[n][n] = { {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
                {5, 2, 0, 0, 0, 0, 0, 0, 0}, 
                {0, 8, 7, 0, 0, 0, 0, 3, 1}, 
                {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
                {9, 0, 0, 8, 6, 3, 0, 0, 5}, 
                {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
                {0, 0, 0, 0, 0, 0, 0, 7, 4}, 
                {0, 0, 5, 2, 0, 6, 3, 0, 0} };


bool solve()
{
    int i;
    int j;
    
    // Getting the coordinates of the cell with 0.
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(grid[i][j] == 0)
            {
                break;
            }
        }
    }
    
    // If the coordinates are the last one, then solved return true.
    if( i == n && j == n)
    {
        return true;
    }
    
    
    // If coordinates are not last, then looping through all the no. which we can fill.
    // We can fill numbers from 1 to n.
    for( int c = 1; c <= n; c++)
    {
        // If the coordinates are safe.
        if(issafe(i,j,c) == true)
        {
            grid[i][j] = c;

            if(solve() == true)
            return true;

            grid[i][j] = 0;
        }
    }

    return false;
}

bool issafe(int i, int j, int c)
{

    // Checking the coordinates, if the similar one's does not exist in same row and column.
    for(int k = 0; k < n; k++)
    {
        if(grid[k][j] == c || grid[i][k] == c)
        {
            return false;
        }

    }
    
        // Checking the coordinates, if the similar one's exists in the sub-grid.

        int s = sqrt(n);
        int rs = i - i%s;
        int cs = j - j%s;

        for(int i = 0; i < s; i++)
        {
            for(int j = 0; j < s; j++)
            {
                if(grid[i+rs][j+cs] == c)
                return false;
            }
        }

        return true;
}

int main()
{
    if(solve())
    {
        for (int i = 0; i < n; i++) 
        { 
            for (int j = 0; j < n; j++) 
            { 
                cout << grid[i][j] << " "; 
            } 
                
        // Newline for new row 
        cout << endl; 
        }
    }
    else
    {
        cout<<"false";
    }
    
}
