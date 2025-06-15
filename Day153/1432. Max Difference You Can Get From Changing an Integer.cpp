class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string maxS = s, minS = s;

        // For maxS: Replace the first non-9 digit with 9 to maximize the number
        char toReplace = 0;
        for (char c : s) {
            if (c != '9') {
                toReplace = c;
                break;
            }
        }
        if (toReplace) {
            for (char& c : maxS) {
                if (c == toReplace) c = '9';
            }
        }

        // For minS:
        // If the first digit is not 1, replace it with 1 (to avoid leading 0)
        // Else replace the first digit that's not 0 or 1 with 0
        toReplace = 0;
        if (s[0] != '1') {
            toReplace = s[0];
            for (char& c : minS) {
                if (c == toReplace) c = '1';
            }
        } else {
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    toReplace = s[i];
                    break;
                }
            }
            if (toReplace) {
                for (int i = 0; i < minS.size(); ++i) {
                    if (minS[i] == toReplace) minS[i] = '0';
                }
            }
        }

        return stoi(maxS) - stoi(minS);
    }
};
