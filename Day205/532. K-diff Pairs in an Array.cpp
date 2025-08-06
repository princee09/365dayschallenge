class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;  
    unordered_map<int, int> freq;
    int count = 0;
    for (int num : nums) {
        freq[num]++;
    }
    for (auto& [num, c] : freq) {
        if (k == 0) {
            if (c > 1) 
                count++;
        } else {
            if (freq.find(num + k) != freq.end())
                count++;
        }
    }

    return count;
    }
};