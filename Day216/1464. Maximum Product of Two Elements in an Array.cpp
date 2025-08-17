class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = 0; // max1 = largest max2 = 2nd largest
        for (int v : nums) {
            if (v > max1) {
                max2 = max1;
                max1 = v;
            } else if (v > max2) {
                max2 = v;
            }
        }
        return (max1 - 1) * (max2 - 1);
    }
};