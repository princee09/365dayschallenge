class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        int half = n / 2;
        for (int i = 1; i <= half; i++) {
            result.push_back(i);
            result.push_back(-i);
        }
        if (n % 2 != 0) {
            result.push_back(0);
        }
        return result;
    }
};