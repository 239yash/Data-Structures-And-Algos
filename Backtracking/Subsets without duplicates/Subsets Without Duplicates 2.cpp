class Solution {
public:
    std::vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::vector<int> temp;
        sort(nums.begin(), nums.end());
        func(nums, 0, temp);
        return ans;
    }
    
    void func(vector<int>& nums, int index, vector<int> temp) {
        ans.push_back(temp);
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) continue;
            
            temp.push_back(nums[i]);
            func(nums, i + 1, temp);
            temp.pop_back();
        }
    }
};
