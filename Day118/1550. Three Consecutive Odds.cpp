class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for (int x : arr) {
            if (x & 1) {             // odd check
                count++;
                if (count == 3)      // found three in a row
                    return true;
            } else {
                count = 0;           // reset on even
            }
        }
        return false;
    }
};