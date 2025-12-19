class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int m = arrays.size();
        int minVal = arrays[0][0], minIdx = 0;
        int maxVal = arrays[0].back(), maxIdx = 0;
        int result = 0;
        for (int i = 1; i < m; i++) {
            int currMin = arrays[i][0];
            int currMax = arrays[i].back();
            if (minIdx != i) {
                result = max(result, currMax - minVal);
            }
            if (maxIdx != i) {
                result = max(result, maxVal - currMin);
            }
            if (currMin < minVal) {
                minVal = currMin;
                minIdx = i;
            }
            if (currMax > maxVal) {
                maxVal = currMax;
                maxIdx = i;
            }
        }
        
        return result;
    }
};