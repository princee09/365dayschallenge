class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> candlePos;
        vector<int> platePrefix(n, 0);
        
        int platesSoFar = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '|') {
                candlePos.push_back(i);
            } else {
                platesSoFar++;
            }
            platePrefix[i] = platesSoFar;
        }
        
        vector<int> ans;
        for (auto& q : queries) {
            int left = q[0], right = q[1];
            
            auto itL = lower_bound(candlePos.begin(), candlePos.end(), left);
            if (itL == candlePos.end() || *itL > right) {
                ans.push_back(0);
                continue;
            }
            int leftCandle = *itL;
            auto itR = upper_bound(candlePos.begin(), candlePos.end(), right);
            if (itR == candlePos.begin()) {
                ans.push_back(0);
                continue;
            }
            itR--;
            int rightCandle = *itR;
            
            if (leftCandle >= rightCandle) {
                ans.push_back(0);
            } else {
                ans.push_back(platePrefix[rightCandle] - platePrefix[leftCandle]);
            }
        }
        
        return ans;
    }
};