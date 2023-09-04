class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long n = 0;
        int z = x;
        while(x) {
          n = n * 10 + x % 10;
          x = x / 10;
        }

        return n == z;
    }
};
