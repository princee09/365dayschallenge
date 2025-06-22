class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        int groups = (n + k - 1) / k;  // ceilng of n/k
        vector<string> result;
        result.reserve(groups);
        
        for (int i = 0; i < groups; ++i) {
            int start = i * k;
            int len   = min(k, n - start);
            // take the substring of up to k characers
            string part = s.substr(start, len);
            // if it's shorter than k pad with 'fill'
            if (len < k) {
                part.append(k - len, fill);
            }
            
            result.emplace_back(move(part));
        }
        
        return result;
    }
};