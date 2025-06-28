class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
       
        for (int i = 0; i < nums.size(); ++i) {
            minHeap.push({nums[i], i});
            if (minHeap.size() > k)
                minHeap.pop();
        }
        vector<pair<int, int>> topK;
        while (!minHeap.empty()) {
            topK.push_back(minHeap.top());
            minHeap.pop();
        }

        sort(topK.begin(), topK.end(), [](auto& a, auto& b) {
            return a.second < b.second; // sort by original index
        });

        vector<int> result;
        for (auto& [val, idx] : topK)
            result.push_back(val);

        return result;
    }
};