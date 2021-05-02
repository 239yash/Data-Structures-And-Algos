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
            if(target == 0)
            {
                v.push_back(v1);
            }
            
            return;
        }

        if(can[i] <= target)
        {
            v1.push_back(can[i]);
            func(v, can, target - can[i], v1, i);
            v1.pop_back();
        }

        func(v, can, target, v1, i+1);
    }
};
