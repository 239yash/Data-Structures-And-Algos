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

void preorder( node * root)
{
    if ( root == NULL)
    {
        return;
    }
    else
    {
        cout<<root -> key<<" ";
        preorder(root -> left);
        preorder(root -> right);
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

    preorder(root);

}
