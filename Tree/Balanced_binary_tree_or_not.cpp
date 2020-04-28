# include<bits/stdc++.h>
using namespace std;

int height( struct node * );
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

bool balanced_tree( node * root)
{

    if(root == NULL)
    {
        return true;
    }

    int lh = height(root -> left);
    int rh = height(root -> right);
    
    if( (abs( lh - rh) <= 1) && balanced_tree(root -> left) == true && balanced_tree(root -> right) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}


int height(node * root)
{
    if( root == NULL)
    {
        return 0;
    }
    int hl = 0;
    int hr = 0;


    hl = height(root -> left);
    hr = height(root -> right);

    return( 1 + max(hl,hr));
}


int main()
{
    node * root = NULL;
    root = new node(10);
    root -> left = new node(8);
    root -> right = new node(2);
    root -> left -> left = new node(4);
    root -> left -> right = new node(4);
    root -> right -> left = new node(1);
    root -> right -> right = new node(1);
    root -> left -> left -> right = new node(2);
    root -> left -> left -> right -> left = new node(1);
    bool res = balanced_tree(root);
    cout<<res;

}
