class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int oddCount = 0, evenCount = 0;
        
        for (int pos : position) {
            if (pos % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }
        
        return min(oddCount, evenCount);
    }
};