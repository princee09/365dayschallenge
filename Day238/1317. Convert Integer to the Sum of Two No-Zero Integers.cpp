class Solution {
private:
    bool isNoZero(int num) {
        while (num > 0) {
            int digit = num % 10;
            if (digit == 0) {
                return false;
            }
            num /= 10;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int a = 1; a <= n / 2; ++a) {
            int b = n - a;
            if (isNoZero(a) && isNoZero(b)) {
                return {a, b};
            }
        }
        return {};
    }
};