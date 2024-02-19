class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        std::vector<int> temp;
        func(nums, ans, temp, 0);
        return ans;
    }
    
    void func(vector<int>& nums, vector<vector<int>>& ans, vector<int> temp, int index) {
        if(index == nums.size()) {
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[index]);
        func(nums, ans, temp, index + 1);
        temp.pop_back();
        while(index + 1 < nums.size() && nums[index] == nums[index + 1]) index++;
        func(nums, ans, temp, index + 1);
        return;
    }
};
