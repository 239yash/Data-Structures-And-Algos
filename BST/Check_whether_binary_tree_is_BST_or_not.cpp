# include<bits/stdc++.h>
using namespace std;

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

bool check_BST( node * root)
{
    if(root == NULL)
    {
        return true;
    }

    if( check_BST( root -> left) == true && check_BST( root -> right) == true)
    {
        if( root -> left == NULL && root -> right != NULL)
        {
            if(root -> key < root -> right -> key)
            {
                return true;
            }
            else
            {
                return false;
            }
            
        }

        if( root -> left != NULL && root -> right == NULL)
        {
            if(root -> key > root -> left -> key)
            {
                return true;
            }
            else
            {
                return false;
            }
            
        }

        if( root -> left == NULL && root -> right == NULL)
        {
            return true;
        }

        if( root -> left != NULL && root -> right != NULL)
        {
            if( root -> key > root -> left -> key && root -> key < root -> right -> key)
            return true;
            else
            {
                return false;
            }
            
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
    root = new node(15);
    root -> left = new node(5);
    root -> left -> left = new node(3);
    root -> right = new node(20);
    root -> right -> left = new node(18);
    root -> right -> left -> left = new node(16);
    root -> right -> right = new node(19);
    bool res = check_BST(root);
    cout<<res;
}
