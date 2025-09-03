class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> lastOccurrence;
        int minLength = INT_MAX;

        for (int i = 0; i < cards.size(); i++) {
            int card = cards[i];
            if (lastOccurrence.find(card) != lastOccurrence.end()) {
                int length = i - lastOccurrence[card] + 1;
                if (length < minLength) {
                    minLength = length;
                }
            }
            lastOccurrence[card] = i;
        }

        return minLength == INT_MAX ? -1 : minLength;
    }
};