class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> used(n, false);
        int unplaced = 0;
        for (int f : fruits) {
            bool placed = false;
            for (int i = 0; i < n; ++i) {
                if (!used[i] && baskets[i] >= f) {
                    used[i] = true; 
                    placed = true;
                    break;         
                }
            }
            if (!placed) {
                ++unplaced;
            }
        }

        return unplaced;
    }
};