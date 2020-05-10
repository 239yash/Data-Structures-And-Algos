# include<bits/stdc++.h>
using namespace std;
//Function declarations
bool solvemaze( int i, int j);
bool issafe(int i, int j);



const int n = 3;
//The given maze or 2-d array.
bool maze[][n] = {{1,0,1},
                {1,1,0},
                {0,1,1}};

bool soln[n][n] = {0};

// The solve function for the starting point and prining solution matrix.
bool solve()
{
    if(solvemaze(0,0) == false)
    {
        cout<<"false"<<endl;
        return false;
    }
    else
    {
        for (int i = 0; i < n; i++) 
        { 
        for (int j = 0; j < n; j++) 
        { 
            cout << soln[i][j] << " "; 
        } 
            
        // Newline for new row 
        cout << endl; 
        }
        cout<<"True"<<endl;
        return true;
    }
    
}

bool solvemaze( int i, int j)
{

    // If the i,j are the last cell of the given matrix.
    // This means that the program has found the route till this cell.
    // If this cell is also safe then route found.

    if( i == n-1 && j == n-1 && issafe(i,j) == true)
    {
        soln[i][j] = 1;
        return true;
    }


    // If th cell is not the last one, so checking whether it is safe or not.
    if( issafe(i,j) == true)
    {
        
        soln[i][j] = 1;

        // If the cell is safe, then checking for the cell just below it.
        if( solvemaze( i+1, j) == true)
        {
            return true;
        }
        else
        {
            // If the cell below it, does not give the True, then checking for the cell just Right to it.
            if(solvemaze(i, j+1) == true)
            {
                return true;
            }
        }

        // If the no one is providing true then this cell is not safe, marking it 0 in the solution.
        soln[i][j] = 0;
        return false; 
    }
}

bool issafe(int i, int j)
{
    return(i < n && j < n && maze[i][j] == 1);
}

int main()
{
    solve();
    return 0;
}
  
 
