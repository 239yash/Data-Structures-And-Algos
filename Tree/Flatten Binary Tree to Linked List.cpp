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
    void flatten(TreeNode* root) {
        func(root);
    }
    
    TreeNode* func(TreeNode* root) {
        if(!root) return root;
        if(root -> left == NULL && root -> right == NULL) return root;
        TreeNode* leftPart = func(root -> left); // Recursive for left part
        TreeNode* rightPart = func(root -> right); // Recursive for right part
        if(leftPart) {
          // If left exists
          // We will go to the rightmost node of left part and add right part to the right of that node
            TreeNode* temp = leftPart;
            while(temp -> right) {
                temp = temp -> right;
            }
            temp -> right = rightPart;
            root -> right = leftPart;
        } else {
            root -> right = rightPart;
        }
        
        root -> left = NULL; // Making root's left NULL, as we have to flatten the tree
        return root;
    }
};
