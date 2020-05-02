# include<bits/stdc++.h>
using namespace std;
void hor_height(struct node*, int, std::map<int, int> &m);

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

void vertical_sum( node * root)
{
    std::map<int, int> m;
    int hh = 0;
    hor_height(root, hh, m);
    map<int, int>::iterator itr;
    for(itr = m.begin(); itr != m.end(); itr ++)
    {
        cout<<(itr -> second)<<" ";
    }

}

void hor_height( node * root, int hh, std::map<int, int> &m)
{
    if( root == NULL)
    {
        return;
    }

    m[hh] = m[hh] + root -> key;

    hor_height(root -> left, hh-1, m);
    hor_height( root -> right, hh+1, m);


}

int main()
{
    node * root = NULL;
    root = new node(50);
    root -> left = new node(20);
    root -> left -> left = new node(10);
    root -> left -> right = new node(30);
    root -> left -> right -> right = new node(35);
    root -> left -> right -> left = new node(25);
    root -> right = new node(60);
    root -> right -> right = new node(65);
    root -> right -> left = new node(55);
    root -> right -> right -> right = new node(70);

    vertical_sum(root);
}
