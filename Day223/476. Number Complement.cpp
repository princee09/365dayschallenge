class Solution {
public:
    int findComplement(int num) {
        unsigned int mask = 1;
        unsigned int n = num;

        while (n > 0) {
            mask <<= 1;
            n >>= 1;
        }

        mask -= 1; 
        return num ^ mask;
    }
};