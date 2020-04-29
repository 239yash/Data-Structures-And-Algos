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

    std::queue<node *> q;
    std::stack<int> s;

    q.push(root);
    bool reverse = false;
    while(q.empty() == false)
    {
        int count = q.size();
        for( int i = 0; i < count; i++)
        {
            node * curr = q.front();
            q.pop();
            if(reverse)
            {
                s.push(curr -> key);
            }
            else
            {
                cout<<curr -> key<<" ";
            }

            if( curr -> left != NULL)
            q.push(curr -> left);
            if( curr -> right != NULL)
            q.push(curr -> right);
        }

        if(reverse)
        {
            while(s.empty() == false)
            {
                cout<<s.top()<<" ";
                s.pop();
            }
        }
            reverse = !reverse;
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
