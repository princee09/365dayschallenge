class Solution {
public:
    int arrangeCoins(int n) {
        long left = 0, right = n;
        
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long coinsNeeded = mid * (mid + 1) / 2;
            
            if (coinsNeeded == n) {
                return mid;
            } else if (coinsNeeded > n) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return right;
    }
};