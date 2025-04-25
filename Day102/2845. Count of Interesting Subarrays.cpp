class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
    unordered_map<int, long long> freq;
    freq.reserve(nums.size());
    
    long long result = 0;
    int prefix_mod = 0;
    freq[0] = 1;
    
    for (int x : nums) {
        int add = (x % modulo == k) ? 1 : 0;
        prefix_mod = (prefix_mod + add) % modulo;
        int need = prefix_mod - k;
        if (need < 0) need += modulo;
        if (freq.count(need))
            result += freq[need];
        freq[prefix_mod]++;
    }
    
    return result;
    }
};
