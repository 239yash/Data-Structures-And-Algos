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

node * BST_insert(node * root, int key)
{
    if(root -> key == key)
    {
        cout<<"THE KEY IS ALREADY PRESENT";
        return root;
    }

    if(root -> key > key)
    {
        if( root -> left == NULL)
        {
            root -> left = new node(key);
            return root;
        }
        else
        {
            BST_insert( root -> left, key);
            return root;
        }
    }

    if(root -> key < key)
    {
        if( root -> right == NULL)
        {
            root -> right = new node(key);
            return root;
        }
        else
        {
            BST_insert(root -> right, key);
            return root;
        }
        
    }
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
    root = BST_insert(root, 19);
    
    lvl_order(root);
}
