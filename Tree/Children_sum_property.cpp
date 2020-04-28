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

bool child_sum( node * root)
{
    if( root -> left == NULL && root -> right == NULL)
    {
        return true;
    }

    int val = root -> key;
    int l, r;

    if( root -> left == NULL)
    l = 0;
    else
    l = root -> left -> key;

    if( root -> right == NULL)
    r = 0;
    else
    r = root -> right -> key;

    if( val == l+r)
    {
        if( child_sum(root -> left) == true && child_sum(root -> right) == true)
        {
            return true;
        }

        else
        {
            return false;
        }
        
    }

    else
    {
        return false;
    }
    
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
    root -> left -> left -> left = new node(1);
    bool res = child_sum(root);
    cout<<res;

}
