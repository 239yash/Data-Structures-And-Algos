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

bool balanced_tree( node * root)
{
    // if both children are null. return true.
    if(root -> left == NULL && root -> right == NULL )
    {
        return true;
    }


    // if both children are not null.
    if( root -> left != NULL && root -> right != NULL)
    {
        // if the reccuring children are true then only return true.
        if( balanced_tree( root -> left) == true && balanced_tree( root -> right) == true)
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
            // if any one of the child is null then return false.
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
    bool res = balanced_tree(root);
    cout<<res;

}
