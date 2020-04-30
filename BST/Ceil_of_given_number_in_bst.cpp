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

int res = INT_MAX;
node * BST_ceil( node * root, int key)
{
    if(root -> key > key)
    {
        res = min(res, root -> key);
        root -> left = BST_floor( root -> left, key);
        return root;
    }

    if(root -> key < key)
    {

        root -> right = BST_floor( root -> right, key);
        return root;
    }

    return NULL;
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
    root = new node(15);
    root -> left = new node(5);
    root -> left -> left = new node(3);
    root -> right = new node(20);
    root -> right -> left = new node(18);
    root -> right -> left -> left = new node(16);
    root -> right -> right = new node(80);
    root = BST_ceil(root, 16);

    cout<<res;

}
