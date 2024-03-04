class Solution {
public:
    std::vector<string> ans;
    vector<string> generateParenthesis(int n) {
        solve("", n, n);
        return ans;
    }
    
    void solve(string temp, int open, int close) {
        if (open == 0 && close == 0) {
            ans.push_back(temp);
            return;
        }
        
        if(open == close)
            solve(temp + "(", open - 1, close);
        else if(open < close) {
            if(open)
                solve(temp + "(", open - 1, close);
            if(close)
                solve(temp + ")", open, close - 1);
        }
    }
};



// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]
