class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (k >= n)
            return "0";
            
        string res;
        res.reserve(n);
        for (char c : num) {
            while (k > 0 && !res.empty() && res.back() > c) {
                res.pop_back();
                --k;
            }
            res.push_back(c);
        }
        if (k > 0) {
            res.resize(res.size() - k);
        }
        size_t idx = 0;
        while (idx < res.size() && res[idx] == '0')
            ++idx;
        string ans = (idx == res.size()) ? "0" : res.substr(idx);
        return ans;
    }
};