class Solution {
public:
    int minDeletions(string s) {
        std::vector<int> count(26, 0);
        for(auto x : s)
            count[x - 'a']++;
        int ans = 0;
        unordered_set<int> st;
        for(int i = 0; i < 26; i++) {
            while(count[i] > 0 && st.find(count[i]) != st.end()) {
                --count[i];
                ++ans;
            }
            st.insert(count[i]);
        }
        return ans;
    }
};
