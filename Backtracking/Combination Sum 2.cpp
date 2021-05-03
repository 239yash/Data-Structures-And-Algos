/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.


Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<int> v1;
        vector<vector<int>> v;
        
        sort(candidates.begin(), candidates.end());
        
        func(0, target, candidates, v1, v);
        return v;

    }
    
    void func(int start, int target, std::vector<int>& cand, vector<int> &v1, vector<vector<int>>& v)
    {
        if(target == 0)
        {
            v.push_back(v1);
            return;
        }

        for(int i = start; i < cand.size(); i++)
        {
            if(cand[i] > target)
                return;
            
            // Here we are checking for iterative duplicates
            // Basically, if adjacents are same. Then we have take only one from that same group.
            // Else, the combinations will be repeated
            if(i && cand[i] == cand[i-1] && i > start)
            {
                continue;
            }

            v1.push_back(cand[i]);
            func(i+1, target - cand[i], cand, v1, v);
            v1.pop_back();
        }
    
    }
};
