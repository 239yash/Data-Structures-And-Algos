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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        std::unordered_map<TreeNode*, TreeNode*> m;
        std::unordered_map<TreeNode*, bool> visited;
        std::queue<TreeNode*> q;
        
        q.push(root);
        while(!q.empty())
        {
            TreeNode* current = q.front();
            q.pop();
            if(current->left)
            {
                m[current->left] = current;
                q.push(current->left);
            }
            
            if(current->right)
            {
                m[current->right] = current;
                q.push(current->right);
            }
        }
        
        q.push(target);
        visited[target] = true;
        int level = 0;
        
        while(!q.empty())
        {
            int n = q.size();
            if(level++ == k) break;
            
            for(int i = 0; i < n; i++)
            {
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr -> left && visited[curr -> left] == false)
                {
                    visited[curr -> left] = true;
                    q.push(curr -> left);
                }
                
                if(curr -> right && visited[curr -> right] == false)
                {
                    visited[curr -> right] = true;
                    q.push(curr -> right);
                }
                
                if(m[curr] && visited[m[curr]] == false)
                {
                    visited[m[curr]] = true;
                    q.push(m[curr]);
                }
            }
        }
        
        std::vector<int> ans;
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr -> val);
        }
        
        return ans;
    }
};
