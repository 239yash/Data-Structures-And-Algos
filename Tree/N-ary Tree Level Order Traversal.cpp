/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

Input: root = [1,null,3,2,4,null,5,6]
Output: [[1],[3,2,4],[5,6]]
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        std::queue<Node*> q;
        q.push(root);
        q.push(NULL);
        std::vector<int> v;
        std::vector<vector<int>> ans;
        
        while(q.size() > 1) {
            auto top = q.front();
            q.pop();
            
            if(top == NULL) {
                q.push(NULL);
                ans.push_back(v);
                v.resize(0);
                continue;
            }
            
            v.push_back(top -> val);
            for(auto x : top -> children)
                q.push(x);
        }
        
        ans.push_back(v);
        return ans;
    }
};
