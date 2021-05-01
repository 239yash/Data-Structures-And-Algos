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
    TreeNode* removeLeafNodes(TreeNode* root, int target)
    {
        bool check = func(root, target);
        if(check == true)
            return NULL;
        return root;
    }
    
    bool func(TreeNode* root, int target)
    {
        if(root == nullptr)
            return false;
        
        // check, if the node is leave node or not
        if(root -> left == nullptr && root -> right == nullptr && root -> val == target)
            return true;
        
        bool le = func(root -> left, target);
        if(le) root -> left = nullptr;

        bool re = func(root -> right, target);
        if(re) root -> right = nullptr;
        
        // After removing the leaf node, new leaf node will be generated
        // If the newly gen leaf node also satisfies the condition
        // We have to remove that also
        if(root -> left == nullptr && root -> right == nullptr && root -> val == target)
            return true;
        else
            return false;
    }
};

/*
Author - Yash Gupta
Leetcode - https://leetcode.com/problems/delete-leaves-with-a-given-value/
*/
