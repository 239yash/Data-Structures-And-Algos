class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        std::vector<vector<int>> ans;
        func(ans, nums, 0, nums.size() - 1);
        return ans;
    }
    
    void func(vector<vector<int>>& ans, vector<int> nums, int start, int end) {
        if(start == end)
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i = start; i <= end; i++)
        {
            if(i != start && nums[i] == nums[start]) continue;
            swap(nums[i], nums[start]);
            func(ans, nums, start + 1, end);
        }
    }
};
