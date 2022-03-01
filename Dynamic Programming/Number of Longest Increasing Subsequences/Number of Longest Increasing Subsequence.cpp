// Create two arrays
// One will contain the length of LIS, ending with nums[i]
// Second array at corresponding index will contain the number of LISs ending with nums[i].
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> len(n, 1);
        std::vector<int> cnt(n, 1);
        int maxLen = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            // for(auto x : len) cout<<x<<" ";cout<<endl;
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    if(len[i] == len[j] + 1) {
                        // cout<<"Cond"<<" "<<i<<" "<<len[i]<<" "<<j<<" "<<len[j];
                        cnt[i] += cnt[j];
                    }
                    if(len[i] < len[j] + 1) {
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    }
                }
            }
            if(maxLen == len[i]) ans += cnt[i];
            if(maxLen < len[i]) {
                maxLen = len[i];
                ans = cnt[i];
            }
        }
        // for(auto x : cnt) cout<<x<<" ";cout<<endl;
        return ans;
    }
};
