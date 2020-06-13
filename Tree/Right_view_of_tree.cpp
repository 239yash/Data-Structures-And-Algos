#include <bits/stdc++.h>
using namespace std;

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

void right_view(node *root)
{
    if (root == NULL)
        return;
    int ans;
    std::queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (q.size() > 1)
    {
        node *curr = q.front();
        q.pop();
        if (curr != NULL)
        {
            ans = curr->key;
            if (curr->left != NULL)
                q.push(curr->left);

            if (curr->right != NULL)
                q.push(curr->right);
        }
        else
        {
            cout << ans << " ";
            q.push(NULL);
        }
    }
    cout << ans << " ";
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

    right_view(root);
}
