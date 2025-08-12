class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        long long total = 0;
        for (int x : arr) total += x;
        if (total % 3 != 0) return false;
        long long target = total / 3;
        int cnt = 0;
        long long cur = 0;
        for (size_t i = 0; i < arr.size(); ++i) {
            cur += arr[i];
            if (cur == target) {
                ++cnt;
                cur = 0;
            }
            if (cnt == 2 && i + 1 < arr.size()) return true;
        }
        return false;
    }
};