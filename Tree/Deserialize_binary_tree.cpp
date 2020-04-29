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

const int empty = -1;
int index1 = 0;

node * de_serialize(vector<int> &arr)
{
    if(index1 == arr.size())
    {
        return NULL;
    }

    int val = arr[index1];
    index1 ++;
    if(val == empty)
    {
        return NULL;
    }

    node * root = new node(val);

    root -> left = de_serialize(arr);
    root -> right = de_serialize(arr);

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
    std::vector<int> v{10,20,40,-1,80,-1,-1,-1,-1};
    root = de_serialize(v);
    lvl_order(root);
}
