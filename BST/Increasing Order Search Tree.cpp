/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* curr;
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* res = new TreeNode(0);
        curr = res;
        func(root);
        return res -> right;
    }
    
    void func(TreeNode* root) {
        if(!root) return;
        func(root -> left);
        root -> left = NULL;
        curr -> right = root;
        curr = root;
        func(root -> right);
    }
};
