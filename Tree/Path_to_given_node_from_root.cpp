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

std::vector<int> v;

bool path( node * root, int value)
{
    if( root == NULL)
    {
        return false;
    }

    if( root -> key == value)
    {
        v.insert(v.begin(),value);
        return true;
    }

    if( path(root -> left, value) == true)
    {
        v.insert(v.begin(), root -> key);
        return true;
    }
    if( path(root -> right, value) == true)
    {
        v.insert(v.begin(), root -> key);
        return true;
    }

    return false;


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
    root -> left -> left -> left = new node(80);
    path(root,20);
    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << " "; 

}
