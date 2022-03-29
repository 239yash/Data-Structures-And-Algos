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
    std::vector<int> ans;
    vector<int> largestValues(TreeNode* root) {
        func(root, 1);
        return ans;
    }
    
    void func(TreeNode* root, int depth) {
        if(!root) return;
        func(root -> left, depth + 1); // Call for root -> left
        func(root -> right, depth + 1); // Call for root -> right
        if(ans.size() < depth) {
            ans.resize(depth, INT_MIN); // Resizing the size of vector according to the maximum depth reached
        }
        
        ans[depth - 1] = max(ans[depth - 1], root -> val); // Updating the value in the ans vector
    }
};
