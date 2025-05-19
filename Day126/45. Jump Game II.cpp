class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;         // Number of jumps made
        int currentEnd = 0;    // End of current jump range
        int farthest = 0;      // Farthest index reachable so far

        for (int i = 0; i < nums.size() - 1; ++i) {
            farthest = max(farthest, i + nums[i]);

            // When we reach the end of current range,
            // we must jump and update the range
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }

        return jumps;
    }
};