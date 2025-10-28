class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        
        for (int num : arr) {
            freq[num]++;
        }
        vector<int> frequencies;
        for (auto& [num, count] : freq) {
            frequencies.push_back(count);
        }
        
        sort(frequencies.rbegin(), frequencies.rend());
        
        int target = n / 2;
        int removed = 0;
        int setCount = 0;
        
        for (int count : frequencies) {
            removed += count;
            setCount++;
            if (removed >= target) {
                break;
            }
        }
        
        return setCount;
    }
};