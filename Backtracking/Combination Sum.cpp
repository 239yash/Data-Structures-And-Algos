class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        std::vector<vector<int>> v;
        std::vector<int> v1;
        int i = 0;

        func(v, candidates, target, v1, i);
        return v;
    }
    
    void func(vector<vector<int>>& v, vector<int>& can, int target, std::vector<int> v1, int i)
    {
        int n = can.size();
        
        if(i == n)
        {
            // Checking if target reached or not.
            if(target == 0)
            {
                // If target reached, pushing v1 in main vector v.
                v.push_back(v1);
            }
            
            return;
        }

        if(can[i] <= target)
        {
            // If can[i] is suitable, taking it and passing the func
            v1.push_back(can[i]);
            func(v, can, target - can[i], v1, i);
            // Backtrack
            v1.pop_back();
        }
        
        // Not taking can[i] and increasing the index by 1
        func(v, can, target, v1, i+1);
    }
};
