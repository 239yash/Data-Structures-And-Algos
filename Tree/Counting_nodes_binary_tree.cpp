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

int count_node(node * root)
{
    if( root == NULL)
    {
        return 0;
    }
    int countl = 0;
    int countr = 0;
    if(root -> left != NULL)
    {
        countl = count_node(root -> left);
    }

    if(root -> right != NULL)
    {
        countr = count_node(root -> right);
    }

    return(1+countl+countr);
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
    int count = count_node(root);
    cout<<count<<" ";

}
