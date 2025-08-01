class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<pair<int,int>> v;
        v.reserve(n);
        for (int i = 0; i < n; ++i) {
            v.emplace_back(score[i], i);
        }
        sort(v.begin(), v.end(), [](const auto &a, const auto &b){
            return a.first > b.first;
        });
        
        vector<string> ans(n);
        
        for (int rank = 0; rank < n; ++rank) {
            int idx = v[rank].second;
            if (rank == 0) {
                ans[idx] = "Gold Medal";
            } else if (rank == 1) {
                ans[idx] = "Silver Medal";
            } else if (rank == 2) {
                ans[idx] = "Bronze Medal";
            } else {
                ans[idx] = to_string(rank + 1);
            }
        }
        
        return ans;
    }
};