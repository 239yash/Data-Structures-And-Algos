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

// Input: root = [3,5,1,6,2,0,8,null,null,7,4]
// Output: [2,7,4]
// Explanation: We return the node with value 2, colored in yellow in the diagram.
// The nodes coloured in blue are the deepest nodes of the tree.
// Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.
// Author - 239yash

class Solution {
public:
    int height;
    
    int findHeight(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(findHeight(root -> left), findHeight(root -> right));
    }
    
    void findNodes(TreeNode* root, int h, std::vector<TreeNode*>& nodes) {
        if(!root) return;
        if(h == height) nodes.push_back(root);
        findNodes(root -> left, h + 1, nodes);
        findNodes(root -> right, h + 1, nodes);
    }
    
    TreeNode* findLCA(TreeNode* root, TreeNode* a, TreeNode* b) {
        if(!root) return NULL;
        if(root == a || root == b) return root;
        TreeNode* left = findLCA(root -> left, a, b);
        TreeNode* right = findLCA(root -> right, a, b);
        if(left && right) return root;
        if(left) return left;
        return right;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        height = findHeight(root);
        std::vector<TreeNode*> nodes;
        findNodes(root, 1, nodes);
        if(nodes.size() == 1) return nodes[0];
        
        TreeNode* ans = findLCA(root, nodes[0], nodes[nodes.size() - 1]);
        return ans;
    }
};
