class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();
        int max_moves = max(stones[n - 1] - stones[1] - (n - 2),
                            stones[n - 2] - stones[0] - (n - 2));
        int min_moves = n;
        int j = 0;

        for (int i = 0; i < n; i++) {
            while (j < n && stones[j] - stones[i] < n) {
                j++;
            }

            int stones_in_window = j - i;
            if (stones_in_window == n - 1 &&
                stones[j - 1] - stones[i] == n - 2) {
                min_moves = min(min_moves, 2);
            } else {
                min_moves = min(min_moves, n - stones_in_window);
            }
        }

        return {min_moves, max_moves};
    }
};