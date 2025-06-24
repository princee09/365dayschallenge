class Solution {
public:
    unordered_map<int, vector<int>> memo;

    vector<int> beautifulArray(int n) {
        if (memo.count(n)) return memo[n];

        vector<int> res;
        if (n == 1) {
            res.push_back(1);
        } else {
            vector<int> odd = beautifulArray((n + 1) / 2);
            for (int x : odd) {
                res.push_back(2 * x - 1);
            }

            vector<int> even = beautifulArray(n / 2);
            for (int x : even) {
                res.push_back(2 * x);
            }
        }

        memo[n] = res;
        return res;
    }
};
