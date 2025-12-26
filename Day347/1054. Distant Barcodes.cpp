class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int n = barcodes.size();
        if (n <= 1) return barcodes;
        
        unordered_map<int, int> freq;
        for (int barcode : barcodes) {
            freq[barcode]++;
        }
        
        priority_queue<pair<int, int>> maxHeap;
        for (auto& [num, count] : freq) {
            maxHeap.push({count, num});
        }
        
        vector<int> result(n);
        int idx = 0;
        pair<int, int> prev = {0, 0};
        
        while (!maxHeap.empty()) {
            auto [count1, num1] = maxHeap.top();
            maxHeap.pop();
            
            result[idx++] = num1;
            count1--;
            
            if (prev.first > 0) {
                maxHeap.push(prev);
            }
            
            prev = {count1, num1};
        }
        
        return result;
    }
};