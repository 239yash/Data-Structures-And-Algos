#include <bits/stdc++.h> 
using namespace std;

//Function declarations.
int find_parent(int);

// Declaring the array size and declaring parent array of n size.
const int n = 5;
int parent[n];

// Function to initialize the parent array.
// Initializing same value as their index because they are their's own parents.
void initialize()
{
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
}

// Function to find the representative of a element inthe parent array.
int find_parent(int x)
{
    // If the element's parent is itself only, then simply return.
    // Else, recursively find for the parent of it.
    if(parent[x] == x)
    {
        return x;
    }
    else
    {
        return(find_parent(parent[x]));
    }
    
}


// Function to do the union of two disjoint sets.
void union_set(int x, int y)
{
    int x_rep = find_parent(x);
    int y_rep = find_parent(y);

    // If the representatives of both are same, then do nothing.
    // Else change the representative of one to another.
    if(x_rep == y_rep)
    {
        return;
    }
    else
    {
        parent[y_rep] = x_rep;
    }
    
}

int main()
{
    initialize();
    union_set(0,2);
    union_set(2,4);

    for(int i = 0; i < n; i++)
    {
        cout<<parent[i]<<" ";
    }
}
