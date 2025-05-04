class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int freq[10][10] = {0};
        int64_t ans = 0;
        for (auto& d : dominoes) {
            int a = d[0], b = d[1];
            if (a > b)
                swap(a, b);
            ans += freq[a][b];
            freq[a][b]++;
        }
        return ans;
    }
};