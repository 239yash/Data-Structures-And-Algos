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
    root -> left = new node(20);
    root -> right = new node(30);
    root -> left -> left = new node(40);
    root -> left -> right = new node(50);
    root -> right -> left = new node(60);
    root -> right -> right = new node(70);
    root -> left -> left -> left = new node(75);
    int h = height(root);
    cout<<h<<" ";

}
