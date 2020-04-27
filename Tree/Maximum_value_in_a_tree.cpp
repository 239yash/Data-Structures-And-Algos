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

int max_val(node * root)
{
    if( root == NULL)
    {
        return INT_MIN;
    }
    int maxl = 0;
    int maxr = 0;

    int val = root -> key;

    maxl = max(val, max_val(root -> left));
    maxr = max(val, max_val(root -> right));

    return(max(maxr,maxl));
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
    int maxi = max_val(root);
    cout<<maxi<<" ";

}
