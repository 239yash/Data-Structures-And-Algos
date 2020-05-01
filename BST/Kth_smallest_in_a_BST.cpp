# include<bits/stdc++.h>
using namespace std;

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

int counti = 0;

void kth_smallest(node * root, int k)
{
    if(root == NULL)
    {
        return;
    }

    kth_smallest(root -> left, k);
    counti ++;
    if(counti == k)
    {
        cout<<root -> key<<" ";
        return;
    }

    kth_smallest(root -> right, k);

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
    kth_smallest(root, 3);
}
