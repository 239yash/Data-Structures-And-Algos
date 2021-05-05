class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        int open = n;
        int close = n;
        std::vector<string> v;
        string s = "";
        
        func(n, open, close, s, v);
        return v;
    }
    
    void func(int n, int open, int close, string s, std::vector<string>& v)
    {
        if(open == 0 && close == 0)
        {
            v.push_back(s);
            return;
        }
        
        if(open == n && close == n)
        {
            func(n, open - 1, close, s + "(", v);
        }
        else
        {
            if(open < close)
            {
                if(open)
                    func(n, open - 1, close, s + "(", v);
                if(close)
                    func(n, open, close - 1, s + ")", v);
            }
            else
            {
                if(open)
                    func(n, open - 1, close, s + "(", v);
            }
        }
    }
};

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]
