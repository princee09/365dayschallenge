class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int i = 1;
        while (i < (int)s.size() && s[i] >= s[i - 1])
            ++i;
        if (i == (int)s.size())
            return n; 
        while (i > 0 && s[i] < s[i - 1]) {
            s[i - 1]--;
            --i;
        }
        for (int j = i + 1; j < (int)s.size(); ++j)
            s[j] = '9';

        return stoi(s);
    }
};