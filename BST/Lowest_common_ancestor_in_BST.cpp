#include <bits/stdc++.h>
using namespace std;
//void path_vector(int, int);
//void path_vec(node, int, int);

struct node
{
    int key;
    node *left;
    node *right;
    node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};

void path_vector(node *root, int x, int y)
{

    if (root == NULL)
    {
        cout << "No LCA";
        return;
    }
    while (true)
    {
        if (root->key < x && root->key < y)
        {
            root = root->right;
        }
        else if (root->key > x && root->key > y)
        {
            root = root->left;
        }
        else
        {
            break;
        }
    }

    cout << root->key;
}

int main()
{
    node *root = NULL;
    root = new node(50);
    root->left = new node(20);
    root->left->left = new node(10);
    root->left->right = new node(30);
    root->left->right->right = new node(35);
    root->left->right->left = new node(25);
    root->right = new node(60);
    root->right->right = new node(65);
    root->right->left = new node(55);
    root->right->right->right = new node(70);
    path_vector(root, 55, 60);
}
