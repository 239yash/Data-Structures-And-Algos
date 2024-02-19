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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p, q);
    }
    
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return NULL;
        if (root -> val == p -> val) return p;
        if (root -> val == q -> val) return q;
        
        TreeNode* left = lca(root -> left, p, q);
        TreeNode* right = lca(root -> right, p, q);
        if (left && right) return root;
        if (left) return left;
        return right;
    }
};
