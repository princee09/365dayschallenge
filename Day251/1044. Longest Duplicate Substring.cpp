class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.size();
        int left = 1, right = n;
        string result;
        vector<int> power(n, 1);
        const int base = 131;
        const int mod = 1e9 + 7;
        for (int i = 1; i < n; i++) {
            power[i] = (1LL * power[i-1] * base) % mod;
        }
        
        auto check = [&](int len) -> string {
            unordered_map<int, vector<int>> hashMap;
            int hash = 0;
            for (int i = 0; i < len; i++) {
                hash = (1LL * hash * base + (s[i] - 'a' + 1)) % mod;
            }
            hashMap[hash] = {0};
            for (int i = len; i < n; i++) {
                hash = (hash - 1LL * power[len-1] * (s[i-len] - 'a' + 1) % mod + mod) % mod;
                hash = (1LL * hash * base + (s[i] - 'a' + 1)) % mod;
                if (hashMap.find(hash) != hashMap.end()) {
                    string current = s.substr(i - len + 1, len);
                    for (int start : hashMap[hash]) {
                        if (s.substr(start, len) == current) {
                            return current;
                        }
                    }
                    hashMap[hash].push_back(i - len + 1);
                } else {
                    hashMap[hash] = {i - len + 1};
                }
            }
            return "";
        };
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            string dup = check(mid);
            if (!dup.empty()) {
                result = dup;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};