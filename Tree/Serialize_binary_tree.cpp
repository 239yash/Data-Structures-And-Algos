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

void serialize( node * root, vector<int> &arr)
{
    if(root == NULL)
    {
        arr.push_back(empty);
        return;
    }
    else
    {
        arr.push_back(root -> key);
    }

    serialize(root -> left, arr);
    serialize(root -> right, arr);
}





int main()
{
    node * root = NULL;
    root = new node(10);
    root -> left = new node(20);
    //root -> right = new node(30);
    root -> left -> left = new node(40);
    //root -> left -> right = new node(50);
    //root -> right -> left = new node(60);
   //root -> right -> right = new node(70);
    root -> left -> left -> right = new node(80);
    std::vector<int> v;
    serialize(root, v);
    for( int i = 0; i < v.size(); i++)
    cout<<v[i]<<" ";

}
