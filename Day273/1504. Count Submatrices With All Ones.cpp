class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> height(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    height[i][j] = (i == 0) ? 1 : height[i-1][j] + 1;
                }
            }
        }
        
        int result = 0;
        
        for (int i = 0; i < m; i++) {
            stack<pair<int, int>> st; 
            int total = 0;
            
            for (int j = 0; j < n; j++) {
                int count = 1;
                
                while (!st.empty() && st.top().first > height[i][j]) {
                    total -= st.top().second * (st.top().first - height[i][j]);
                    count += st.top().second;
                    st.pop();
                }
                
                total += height[i][j];
                result += total;
                st.push({height[i][j], count});
            }
        }
        
        return result;
    }
};