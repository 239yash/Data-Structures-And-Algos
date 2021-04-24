/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == NULL)
            return NULL;
        
        if(root == p || root == q)
            return root;
        
        TreeNode* left_part = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right_part = lowestCommonAncestor(root -> right, p, q);
        
        if(left_part != NULL && right_part != NULL)
            return root;
        else
        {
            if(left_part)
                return left_part;
            else
                return right_part;
        }
    }
};
