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
    root = new node(10);
    root -> left = new node(20);
    root -> right = new node(30);
    root -> left -> left = new node(40);
    root -> left -> right = new node(50);
    root -> right -> left = new node(60);
    root -> right -> right = new node(70);

    lvl_order(root);

}
