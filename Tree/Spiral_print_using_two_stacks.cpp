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

void spiral_print( node * root)
{
    if( root == NULL)
    {
        return;
    }

    std::stack<node *> s1;
    std::stack<node * > s2;

    s1.push(root);
    while( s1.empty() == false || s2.empty() == false)
    {
        while (s1.empty() == false)
        {
            node * curr = s1.top();
            cout<< curr -> key<<" ";
            s1.pop();
            if(curr -> left != NULL)
            s2.push(curr -> left);
            if(curr -> right != NULL)
            s2.push(curr -> right);
        }

        cout<<endl;

        while (s2.empty() == false)
        {
            node * curr = s2.top();
            cout<< curr -> key<<" ";
            s2.pop();
            if(curr -> right != NULL)
            s1.push(curr -> right);
            if(curr -> left != NULL)
            s1.push(curr -> left);
        }

        cout<<endl;
        
        
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
    spiral_print(root);
}
