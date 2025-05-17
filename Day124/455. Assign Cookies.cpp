class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0;  // index for children (greed factors)
        int j = 0;  // index for cookies (sizes)
        int content = 0;
        
        // Scan through both arrays:
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                // Cookie j can satisfy child i
                content++;
                i++;
                j++;
            } else {
                // Cookie too small, try next larger cookie
                j++;
            }
        }
        return content;
    }
};