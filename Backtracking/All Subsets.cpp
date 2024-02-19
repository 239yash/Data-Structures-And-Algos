class Solution {
public:
    std::vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<int> temp;
        int index = 0;
        func(nums, index, temp);
        return ans;
    }
    
    void func(vector<int>& nums, int index, vector<int> temp) {
        if (index >= nums.size()) {
            ans.push_back(temp);
            return;
        }
        
        func(nums, index + 1, temp);
        temp.push_back(nums[index]);
        func(nums, index + 1, temp);
    }
};
