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

bool BST_search( node * root, int key)
{
    if(root == NULL)
    {
        return false;
    }

    if(root -> key == key)
    {
        return true;
    }

    if( BST_search(root -> left, key) == true || BST_search(root -> right, key) == true)
    {
        return true;
    }
    else
    {
        return false;
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
    if(BST_search(root, 21))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    
    lvl_order(root);
}
