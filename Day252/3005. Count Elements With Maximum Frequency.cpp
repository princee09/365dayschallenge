class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101] = {0};
        for (int num : nums) {
            freq[num]++;
        }
        int maxFreq = 0;
        for (int i = 1; i <= 100; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
            }
        }
        int total = 0;
        for (int i = 1; i <= 100; i++) {
            if (freq[i] == maxFreq) {
                total += maxFreq;
            }
        }
        return total;
    }
};