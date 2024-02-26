class Solution {
public:
    std::unordered_map<string, int> mp;
    std::vector<string> ans;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        std::vector<string> temp;
        for (auto x : wordDict) 
            mp[x]++;
        func(s, 0, temp);
        return ans;
    }
    
    void func(string s, int start, vector<string> curr) {
        if (start == s.size()) {
            string t = "";
            for (auto x : curr) {
                t = t + x + " ";
            }
            t.pop_back();
            ans.push_back(t);
            return;
        }
        
        for (int i = start; i < s.size(); i++) {
            string temp = s.substr(start, i - start + 1);
            if (mp.find(temp) != mp.end()) {
                curr.push_back(temp);
                func(s, i + 1, curr);
                curr.pop_back();
            }
        }
    }
};






// Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

// Example 1:

// Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
// Output: ["cats and dog","cat sand dog"]
// Example 2:

// Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
// Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
// Explanation: Note that you are allowed to reuse a dictionary word.
// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: []
