int maxDiff(Node* root)
{
    // Your code here 
    int res = INT_MIN;
    calc(root, res);
    return res;
}

int calc(Node* root, int & res)
{
    if(root == NULL)
    {
        return INT_MAX;
    }
    
    if(root -> left == NULL && root -> right == NULL)
    {
        return root -> data;
    }
    
    int l = calc(root -> left, res);
    int r = calc(root -> right, res);
    int m = min(l,r);
    
    res = max(res, root -> data - m);
    return min(m, root -> data);
}
