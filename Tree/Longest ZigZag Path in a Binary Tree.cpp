class Solution {
public:
    int maxi = 0;
    int longestZigZag(TreeNode* root)
    {
        if(root -> left == nullptr && root -> right == nullptr)
            return 0;
        
        maxi = 0;
        func(root, 0, 0);
        func(root, 1, 0);
        return maxi;
    }
    
    void func(TreeNode* t, int dir, int ans)
    {
        if(!t) return;
        maxi = max(maxi, ans);
        
        if(dir == 1)
        {
            func(t -> right, 0, ans+1);
            func(t -> left, 1, 1);
        }
        else
        {
            func(t -> left, 1, ans+1);
            func(t -> right, 0, 1);
        }
    }
};
