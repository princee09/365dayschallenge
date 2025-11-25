class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        int ans = -1;
        for (char c = 'a'; c <= 'z'; c++) {
            vector<int> lengths;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == c) {
                    cnt++;
                } else {
                    if (cnt > 0) {
                        lengths.push_back(cnt);
                        cnt = 0;
                    }
                }
            }
            if (cnt > 0) {
                lengths.push_back(cnt);
            }
            if (lengths.empty()) continue;
            sort(lengths.rbegin(), lengths.rend());
            int max_len = lengths[0];
            for (int k = max_len; k >= 1; k--) {
                int total = 0;
                for (int L : lengths) {
                    if (L < k) break;
                    total += (L - k + 1);
                    if (total >= 3) {
                        ans = max(ans, k);
                        break;
                    }
                }
                if (total >= 3) {
                    break;
                }
            }
        }
        
        return ans;
    }
};