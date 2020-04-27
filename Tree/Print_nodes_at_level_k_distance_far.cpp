# include<bits/stdc++.h>
using namespace std;

// Function declaration line, just below this comment.
struct node{
    int key;
    node * left;
    node * right;
    node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};

void print_kdist( node * root, int k)
{
    if( root == NULL)
    {
        return;
    }

    if( k == 0)
    {
        cout<< root -> key <<" ";
    }
    else
    {
        print_kdist(root -> left, k-1);
        print_kdist(root -> right, k-1);
    }
    
}


int main()
{
    node * root = NULL;
    root = new node(10);
    root -> left = new node(20);
    root -> right = new node(30);
    root -> left -> left = new node(40);
    root -> left -> right = new node(50);
    root -> right -> left = new node(60);
    root -> right -> right = new node(70);
    root -> left -> left -> left = new node(75);
    int k = 2;
    print_kdist(root,k);

}
