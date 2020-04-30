# include<bits/stdc++.h>
using namespace std;
struct node * get_successor( struct node *);
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
node * BST_delete(node * root, int key)
{
    if( root == NULL)
    {
        return root;
    }

    if( root -> key > key)
    {
        root -> left = BST_delete(root -> left, key);
    }
    else if( root -> key < key)
    {
        root -> right = BST_delete(root -> right, key);
    }
    else
    {
        if( root -> left == NULL)
        {
            node * temp = root -> right;
            delete root;
            return temp;
        }

        else if( root -> right == NULL)
        {
            node * temp = root -> left;
            delete root;
            return temp;
        }

        else
        {
            node * temp = get_successor(root -> right);
            root -> key = temp -> key;
            root -> right = BST_delete(root -> right, temp -> key);
        }
        return root;
        
    }
    
}

node * get_successor(node * root)
{
    root = root -> right;
    while(root != NULL && root -> left != NULL)
    {
        root = root  -> left;
    }
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
    root = new node(15);
    root -> left = new node(5);
    root -> left -> left = new node(3);
    root -> right = new node(20);
    root -> right -> left = new node(18);
    root -> right -> left -> left = new node(16);
    root -> right -> right = new node(80);
    root = BST_delete( root, 80);
    
    lvl_order(root);
}
