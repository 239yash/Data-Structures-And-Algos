class Solution {
public:
    int minNumberOfFrogs(string s) {
        std::vector<int> count(5, 0);
        int ans = INT_MIN;
        int temp = 0;
        for(auto x : s) {
            if(x == 'c') {
                count[0]++;
                temp++;
                ans = max(ans, temp);
            } else if(x == 'r') {
                count[1]++;
                if(count[1] > count[0]) return -1;
            } else if(x == 'o') {
                count[2]++;
                if(count[2] > count[1]) return -1;
            } else if(x == 'a') {
                count[3]++;
                if(count[3] > count[2]) return -1;
            } else if(x == 'k') {
                count[4]++;
                if(count[4] > count[3]) return -1;
                temp--;
                for(int i = 0; i < 5; i++)
                    count[i]--;
            } else {
                return -1;
            }
        }
        for(int i = 0; i < 5; i++) 
            if(count[i])
                return -1;
        return ans;
    }
};


// You are given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak at the same time, so multiple "croak" are mixed.
// Return the minimum number of different frogs to finish all the croaks in the given string.
// A valid "croak" means a frog is printing five letters 'c', 'r', 'o', 'a', and 'k' sequentially. The frogs have to print all five letters to finish a croak. If the given string is not a combination of a valid "croak" return -1.

 

// Example 1:

// Input: croakOfFrogs = "croakcroak"
// Output: 1 
// Explanation: One frog yelling "croak" twice.
  
 
// Example 2:
// Input: croakOfFrogs = "crcoakroak"
// Output: 2 
// Explanation: The minimum number of frogs is two. 
// The first frog could yell "crcoakroak".
// The second frog could yell later "crcoakroak".
  
  
// Example 3:
// Input: croakOfFrogs = "croakcrook"
// Output: -1
// Explanation: The given string is an invalid combination of "croak" from different frogs.
