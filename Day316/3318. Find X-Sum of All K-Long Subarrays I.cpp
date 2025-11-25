class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> result;
        
        for (int i = 0; i <= n - k; i++) {
            int freq[51] = {0};
            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }
            vector<pair<int, int>> elements;
            for (int val = 1; val <= 50; val++) {
                if (freq[val] > 0) {
                    elements.push_back({val, freq[val]});
                }
            }
            sort(elements.begin(), elements.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                if (a.second != b.second) {
                    return a.second > b.second;
                }
                return a.first > b.first;
            });
            int sum = 0;
            int take = min(x, (int)elements.size());
            for (int idx = 0; idx < take; idx++) {
                sum += elements[idx].first * elements[idx].second;
            }
            
            result.push_back(sum);
        }
        
        return result;
    }
};