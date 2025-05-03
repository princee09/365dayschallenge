class Solution {
public:
    int mySqrt(int x) {
        // Binary search in [0, x] for floor(sqrt(x))
        long long left = 0, right = x;
        int ans = 0;
        
        while (left <= right) {
            long long mid = (left + right) / 2;
            if (mid * mid <= x) {
                ans = mid;          // mid is a valid sqrt candidate
                left = mid + 1;     // try to find a larger one
            } else {
                right = mid - 1;    // mid^2 too big, go lower
            }
        }
        
        return ans;
    }
};
