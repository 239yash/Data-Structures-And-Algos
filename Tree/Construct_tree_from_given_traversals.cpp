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

int preindex = 0;

node * construct_tree( int in[], int pre[], int is, int ie)
{
    if( is > ie)
    {
        return NULL;
    }

    node* root = new node(pre[preindex ++]);

    if( is == ie)
    {
        return root;
    }

    int inindex;
    for( int i = is; i < ie; i++)
    {
        if( in[i] == root -> key)
        {
            inindex = i;
            break;
        }
    }

    root -> left = construct_tree(in, pre, is, inindex -1);
    root -> right = construct_tree(in, pre, inindex+1, ie);
    return root;
}

void lvl_order( node * root)
{
    if(root == NULL){return;}
    std::queue<node*> q;
    q.push(root);

    while(q.empty() == false)
    {
        node * curr = q.front();
        q.pop();
        cout<< curr -> key << " ";
        
        if(curr -> left != NULL)
        q.push(curr -> left);

        if(curr -> right != NULL)
        q.push(curr -> right);
    }
}

int main()
{
    node * root = NULL;
    int in[] ={20,10,40,30,50};
    int pre[] = {10,20,30,40,50};
    int is = 0;
    int ie = 4;
    root = construct_tree(in, pre, is, ie);

    lvl_order(root);

}
