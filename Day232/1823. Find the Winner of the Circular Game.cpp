class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner = 0; // base case when only 1 person left
        for (int i = 2; i <= n; i++) {
            winner = (winner + k) % i;
        }
        return winner + 1;
    }
};