class Solution {
public:
    vector<int> splitIntoFibonacci(string num) {
        vector<int> result;
        backtrack(num, 0, result);
        return result;
    }
private:
    bool backtrack(const string& num, int start, vector<int>& result) {
        if (start == num.size() && result.size() >= 3) {
            return true;
        }
        long long current = 0;
        for (int i = start; i < num.size(); i++) {
            if (i > start && num[start] == '0') {
                break;
            }
            current = current * 10 + (num[i] - '0');
            if (current > INT_MAX) {
                break;
            }
            int n = result.size();
            if (n < 2) {
                result.push_back(current);
                if (backtrack(num, i + 1, result)) {
                    return true;
                }
                result.pop_back();
            } 
            else {
                long long sum = (long long)result[n - 1] + result[n - 2];
                if (current > sum) {
                    break;
                }
                if (current == sum) {
                    result.push_back(current);
                    if (backtrack(num, i + 1, result)) {
                        return true;
                    }
                    result.pop_back();
                }
            }
        }
        
        return false;
    }
};