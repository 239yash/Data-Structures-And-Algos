# include<bits/stdc++.h>
using namespace std;
//Function declarations
bool solve_queen(int col);

const int n = 4;
bool solution[n][n] = {0};

// Function to check whether the placed cell is not attacking any other cell.
bool issafe(int row, int col)
{
    // If the placed cell is attacking any cell in the same row.
    for(int i = 0; i < col; i++)
    {
        if(solution[row][i] == 1)
        return false;
    }


    // If the placed cell is attacking any other cell in diagonal upwards
    for(int i = row, j = col; i >= 0, j >= 0; i--, j--)
    {
        if(solution[i][j] == 1)
        return false;
    }


    // If the placed cell is attacking any other cell in diagonal downwards.
    for(int i = row, j = col; i < 0, j >= 0; i++, j--)
    {
        if(solution[i][j] == 1)
        return false;
    }

    return true;
}


bool n_queen()
{
    // For printing the solution matrix.
    if(solve_queen(0) == true)
    {
        cout<<"True"<<endl;
        for (int i = 0; i < n; i++) 
        { 
            for (int j = 0; j < n; j++) 
            { 
                cout << solution[i][j] << " "; 
            } 
                
            // Newline for new row 
            cout << endl; 
        }

    }
    else
    {
        cout<<"False";
        return false;
    }
    
}

bool solve_queen(int col)
{
    // If the column is the last one, then return True.
    if( col == n)
    {
        return true;
    }


    // If the column is not the last one so check for the issafe function.
    // Run a loop across whole row, where to place the cell.
    // The column no. will be fixed.
    for( int i = 0; i < n; i++)
    {
        // Column no. is fixed.
        if(issafe(i,col) == true)
        {
            solution[i][col] = 1;
            
            if(solve_queen(col+1) == true)
            return true;

            solution[i][col] = 0;
        }
    }
    return false;
}


int main()
{
    n_queen();
    return 0;
}
 
