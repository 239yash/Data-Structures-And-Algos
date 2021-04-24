class Solution {
public:
    int mini = INT_MAX;
    TreeNode* prev = NULL;
    
    int minDiffInBST(TreeNode* root)
    {
        if(root -> right != nullptr)
            minDiffInBST(root -> right);
        
        if(prev != NULL)
            mini = min(mini, abs(root -> val - prev -> val));
        
        prev = root;
        
        if(root -> left != nullptr)
            minDiffInBST(root -> left);
        
        return mini;
    }
};
