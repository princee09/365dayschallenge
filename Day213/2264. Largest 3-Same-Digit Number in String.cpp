class Solution {
public:
    string largestGoodInteger(string num) {
        char best = 0;
        for (int i = 0; i <= (int)num.size() - 3; i++) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                best = max(best, num[i]);
            }
        }
        return best ? string(3, best) : "";
    }
};