class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        int countEven = 0, countOdd = 0;
        int altStartEven = 0, altStartOdd = 0;
        for (int x : nums) {
            if (x % 2 == 0) {
                ++countEven;
            } else {
                ++countOdd;
            }
            if (altStartEven % 2 == 0) {
                // an even number
                if (x % 2 == 0) {
                    ++altStartEven;
                }
            } else {
                // an odd number
                if (x % 2 != 0) {
                    ++altStartEven;
                }
            }
            if (altStartOdd % 2 == 0) {
                // an odd number
                if (x % 2 != 0) {
                    ++altStartOdd;
                }
            } else {
                // an even number
                if (x % 2 == 0) {
                    ++altStartOdd;
                }
            }
        }
        int bestAlt = max(altStartEven, altStartOdd);
        int bestSame = max(countEven, countOdd);
        return max(bestSame, bestAlt);
    }
};