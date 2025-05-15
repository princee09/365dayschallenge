class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;

        map<int, int> count;
        // Count occurrences of each card
        for (int card : hand) {
            ++count[card];
        }

        // Attempt to form groups starting from the smallest card
        for (auto it = count.begin(); it != count.end(); ++it) {
            int start = it->first;
            int cnt = it->second;
            if (cnt > 0) {
                // For each of the next groupSize consecutive cards, reduce count
                for (int card = start; card < start + groupSize; ++card) {
                    auto jt = count.find(card);
                    if (jt == count.end() || jt->second < cnt) {
                        return false;
                    }
                    jt->second -= cnt;
                }
            }
        }
        return true;
    }
};