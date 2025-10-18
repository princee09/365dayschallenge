class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (const string& word : words) {
            freq[word]++;
        }
        
        auto comp = [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first; 
            }
            return a.second > b.second; 
        };
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> minHeap(comp);
        
        for (const auto& [word, count] : freq) {
            minHeap.push({word, count});
            
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        vector<string> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().first);
            minHeap.pop();
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};