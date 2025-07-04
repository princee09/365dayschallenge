class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
    vector<int> res(n, 0);
    
    if (k == 0) return res;

    int start = k > 0 ? 1 : n + k;
    int end = k > 0 ? k : n - 1;
    int sum = 0;
    for (int i = start; i <= end; ++i) {
        sum += code[i % n];
    }

    for (int i = 0; i < n; ++i) {
        res[i] = sum;
        sum -= code[start % n];
        start++;
        end++;
        sum += code[end % n];
    }
    return res;
    }
};