class Solution {
public:
    int findLucky(vector<int>& arr) {
         // Frequency array of size 501 (1 to 500)
        int freq[501] = {0};
        // Count the frequency of each number
        for (int num : arr) {
            freq[num]++;
        }
        // Traverse from largest to smallest to find the largest lucky number
        for (int i = 500; i >= 1; --i) {
            if (freq[i] == i) {
                return i;
            }
        }
        return -1; // No lucky number found
    }
};