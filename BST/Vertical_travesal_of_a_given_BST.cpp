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


void vertical_traversal( node * root)
{
    std::map<int, std::vector<int>> m;
    std::queue<pair< node*, int>> q;

    q.push({root, 0});
    while(q.empty() == false)
    {
        auto p = q.front();
        node * curr = p.first;
        int hh = p.second;

        m[hh].push_back(curr -> key);

        q.pop();

        if(curr -> left != NULL)
        q.push({curr -> left, hh-1});

        if(curr -> right != NULL)
        q.push({curr -> right, hh +1});
    }

    for( auto p : m)
    {
        std::vector<int> v = p.second;
        for( auto x : v)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }


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

    vertical_traversal(root);
}
