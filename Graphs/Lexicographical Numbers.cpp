class Solution {
public:
    std::vector<int> ans;
    vector<int> lexicalOrder(int n) {
        func(0, n);
        return ans;
    }
    
    void func(int curr, int n) {
        for (int i = 0; i <= 9; i++) {
            if (curr + i <= n && curr + i != 0) {
                ans.push_back(curr + i);
                func((curr + i) * 10, n);
            }
        }
    }
};



// Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

// You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

 

// Example 1:

// Input: n = 13
// Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
// Example 2:

// Input: n = 2
// Output: [1,2]
 

// Constraints:

// 1 <= n <= 5 * 104
