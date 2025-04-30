class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int num : nums) {
            // Convert number to string and check if its length is even
            if (to_string(num).size() % 2 == 0) {
                ++count;
            }
        }
        return count;
    }
};