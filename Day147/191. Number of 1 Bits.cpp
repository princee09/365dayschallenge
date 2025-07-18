class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n &= (n - 1); // clears the lowest set bit
            count++;
        }
        return count;
    }
};
