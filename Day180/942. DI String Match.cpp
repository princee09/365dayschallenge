class Solution {
public:
    vector<int> diStringMatch(string s) {
        int low = 0, high = s.length();
        vector<int> result;

        for (char ch : s) {
            if (ch == 'I') {
                result.push_back(low++);
            } else {
                result.push_back(high--);
            }
        }
        result.push_back(low);  

        return result;
    }
};