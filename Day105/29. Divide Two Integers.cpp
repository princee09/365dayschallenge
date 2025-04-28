class Solution {
public:
    int divide(int dividend, int divisor) {
        // Special case: if dividend is INT_MIN and divisor is -1, result overflows
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        // Convert dividend and divisor to long long before taking absolute
        long long dvd = static_cast<long long>(dividend);
        long long dvs = static_cast<long long>(divisor);
        
        // Find the sign of result
        bool negative = (dvd < 0) ^ (dvs < 0);
        
        // Work with positive numbers
        dvd = abs(dvd);
        dvs = abs(dvs);
        
        long long result = 0;
        
        // Try to subtract divisor multiples from dividend using bit shifts
        for (int i = 31; i >= 0; --i) {
            if ((dvd >> i) >= dvs) {
                result += 1LL << i;
                dvd -= dvs << i;
            }
        }
        
        if (negative) result = -result;
        
        return result;
    }
};
