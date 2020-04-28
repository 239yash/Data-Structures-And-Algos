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

int max_width(node * root)
{

    if( root == NULL)
    {
        return 0;
    }
    int count = 0;
    int res = 1;

    std::queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(q.size() > 1)
    {
        node * curr = q.front();
        q.pop();

        if( curr == NULL)
        {
            count = 0;
            q.push(NULL);
            continue;
        }

        if( curr -> left != NULL)
        {
            q.push( curr -> left);
            count ++;
        }

        if( curr -> right != NULL)
        {
            q.push( curr -> right);
            count ++;
        }

        res = max(res,count);

        
    }

    return res;

}

int main()
{
    node * root = NULL;
    root = new node(10);
    root -> left = new node(8);
    root -> right = new node(2);
    root -> left -> left = new node(4);
    root -> left -> right = new node(4);
    root -> right -> left = new node(1);
    root -> right -> right = new node(1);
    root -> left -> left -> right = new node(2);
    root -> left -> left -> right -> left = new node(1);
    int res = max_width(root);
    cout<<res;

}
