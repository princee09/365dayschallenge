class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> cnt(10, 0);
        for (int d : digits) cnt[d]++;

        vector<int> res;
        // hunds = 1..9 (no leading zero)
        for (int h = 1; h <= 9; ++h) {
            if (cnt[h] == 0) continue;
            cnt[h]--;
            // tens = 0..9
            for (int t = 0; t <= 9; ++t) {
                if (cnt[t] == 0) continue;
                cnt[t]--;
                // units = even digits only: 0,2,4,6,8
                for (int u = 0; u <= 8; u += 2) {
                    if (cnt[u] > 0) {
                        int num = 100*h + 10*t + u;
                        res.push_back(num);
                    }
                }
                cnt[t]++;
            }
            cnt[h]++;
        }
        // loops generate in increasing order, so no need to sort or dedupe
        return res;
    }
};