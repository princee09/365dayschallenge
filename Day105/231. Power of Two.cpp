class Solution {
public:
    bool isPowerOfTwo(int n) {
        // A positive power of two has exactly one bit set.
        // n & (n - 1) unsets the lowest set bit.
        // If the result is zero, there was only one bit.
        return n > 0 && (n & (n - 1)) == 0;
    }
};
