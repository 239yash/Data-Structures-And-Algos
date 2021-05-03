/*

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.

*/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        std::vector<vector<int>> v;
        std::vector<int> v1;
        int start = 1;
        
        func(start, k, n, v1, v);
        return v;
    }
    
    void func(int start, int k, int n, std::vector<int>& v1, std::vector<vector<int>>& v)
    {
        // Check if target is zero and size is k
        if(n == 0 && v1.size() == k)
        {
            v.push_back(v1);
            return;
        }
        
        // If size < k.
        if(v1.size() < k)
        {
            // Checking for the possibility of each number to pick or not pick
            for(int i = start; i <= 9; i++)
            {
                if(n - i < 0)
                    break;
                
                v1.push_back(i);
                func(i+1, k, n - i, v1, v);
                v1.pop_back();
            }
        }
    }
};
