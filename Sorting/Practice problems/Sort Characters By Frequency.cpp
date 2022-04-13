class Solution {
public:
    string frequencySort(string s) {
        if(!s.size()) return "";
        std::vector<int> freq(256, 0);
        for(auto x : s)
            freq[x]++;
        string ans = "";
        int mx, index;
        for(auto x : s) {
            mx = 0;
            index = -1;
            for(int i = 0; i < 256; ++i) {
                if(mx < freq[i]) {
                    mx = freq[i];
                    index = i;
                }
            }
            
            if(mx == 0) return ans;
            for(int i = 0; i < freq[index]; i++) 
                ans += char(index);
            freq[index] = 0;
        }
        return ans;
    }
};
