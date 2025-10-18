class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        priority_queue<pair<int, char>> maxHeap;
        for (const auto& [ch, count] : freq) {
            maxHeap.push({count, ch});
        }
        
        string result = "";
        
        while (!maxHeap.empty()) {
            auto [count1, char1] = maxHeap.top();
            maxHeap.pop();
            
            if (result.empty() || result.back() != char1) {
                result += char1;
                count1--;
                if (count1 > 0) {
                    maxHeap.push({count1, char1});
                }
            } else {
                if (maxHeap.empty()) {
                    return ""; 
                }
                
                auto [count2, char2] = maxHeap.top();
                maxHeap.pop();
                
                result += char2;
                count2--;
                
                if (count2 > 0) {
                    maxHeap.push({count2, char2});
                }
                maxHeap.push({count1, char1});
            }
        }
        
        return result;
    }
};