class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        if(nums.size() == 1 || nums.size() == 0) return 0;
        
        int start = -1, end = -1;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < nums[i - 1])
            {
                if(start == -1)
                {
                    start = i;
                    end = i;
                }
                else
                    end = i;
            }
        }
        
        if(start == -1 && end == -1) return 0;
        
        maxi = nums[start];
        mini = nums[start];
        for(int i = 0; i < nums.size(); i++)
        {
            if(i <= end)
                maxi = max(maxi, nums[i]);
            if(i >= start)
                mini = min(mini, nums[i]);
        }
        
        // cout<<mini<<" "<<maxi<<endl;
        
        int ans = end - start + 1;
        
        int curr = end + 1;
        while(curr < nums.size() && maxi > nums[curr])
        {
            ans++;
            curr++;
        }
        
        curr = start - 1;
        while(curr >= 0 && mini < nums[curr])
        {
            ans++;
            curr--;
        }
        
        return ans;
    }
};
