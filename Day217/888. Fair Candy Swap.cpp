class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        long long sumA = 0, sumB = 0;
        for (int x : aliceSizes)
            sumA += x;
        for (int x : bobSizes)
            sumB += x;
        long long delta = (sumA - sumB) / 2;

        unordered_set<int> bobSet;
        bobSet.reserve(bobSizes.size() * 2);
        for (int b : bobSizes)
            bobSet.insert(b);

        for (int a : aliceSizes) {
            long long want = a - delta; 
            if (want >= INT_MIN && want <= INT_MAX &&
                bobSet.find((int)want) != bobSet.end()) {
                return {a, (int)want};
            }
        }

        return {};
    }
};