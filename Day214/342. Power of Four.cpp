class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == 1)
            return true;
        
        if (n <= 0 || n % 4 != 0)
            return false;
        // Recursively check by dividing n by 4
        return isPowerOfFour(n / 4);
    }
};