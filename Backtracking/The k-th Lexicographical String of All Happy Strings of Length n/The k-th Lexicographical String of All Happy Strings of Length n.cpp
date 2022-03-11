class Solution {
public:
    string res = "";
    string getHappyString(int n, int k) {
        func(n, k, "");
        return res;
    }
    
    void func(int n, int& k, string s) {
        if(n == 0) {
            if(--k == 0) res = s;
            return;
        }
        
        for(char ch = 'a'; ch <= 'c'; ch++) {
            if(s.size() > 0 && ch == s[s.size() - 1]) continue;
            s.push_back(ch);
            func(n - 1, k, s);
            s.pop_back();
        }
    }
};
