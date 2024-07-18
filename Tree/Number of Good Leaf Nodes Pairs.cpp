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
    int ans = 0;
    int countPairs(TreeNode* root, int distance) {
        func(root, distance);
        return ans;
    }
    
    vector<int> func(TreeNode* root, int distance) {
        if (root == nullptr)
            return {};
        if (root -> left == nullptr
           && root -> right == nullptr) 
            return {1};
        
        vector<int> l = func(root -> left, distance);
        vector<int> r = func(root -> right, distance);
        
        for(auto x : l) {
            for(auto y : r) {
                if (x + y <= distance) ans++;
            }
        }
        
        vector<int> temp;
        for (auto x : l) {
            temp.push_back(x + 1);
        }
        for (auto x : r) {
            temp.push_back(x + 1);
        }
        return temp;
    }
};







// You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.

// Return the number of good leaf node pairs in the tree.

 

// Example 1:


// Input: root = [1,2,3,null,4], distance = 3
// Output: 1
// Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.
// Example 2:


// Input: root = [1,2,3,4,5,6,7], distance = 3
// Output: 2
// Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not good because the length of ther shortest path between them is 4.
// Example 3:

// Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
// Output: 1
// Explanation: The only good pair is [2,5].
 

// Constraints:

// The number of nodes in the tree is in the range [1, 210].
// 1 <= Node.val <= 100
// 1 <= distance <= 10
