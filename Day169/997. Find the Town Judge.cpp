class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustScore(n + 1, 0); // index 0 is unused

        for (auto& t : trust) {
            int a = t[0], b = t[1];
            trustScore[a]--; // a trusts someone
            trustScore[b]++; // b is trusted by someone
        }

        for (int i = 1; i <= n; ++i) {
            if (trustScore[i] == n - 1)
                return i; // only the judge will have this trust score
        }

        return -1;
    }
};