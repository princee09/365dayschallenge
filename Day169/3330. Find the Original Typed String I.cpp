class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.length();
    int count = 1; // original string is always a valid possibility

    for (int i = 0; i < n;) {
        int j = i;
        // count length of group of same characters
        while (j < n && word[j] == word[i]) j++;
        int len = j - i;
        // if group length > 1, we can reduce this group once
        if (len > 1) {
            count += len - 1; // e.g., "cccc" → "ccc", "cc", "c"
        }
        i = j; // move to next group
    }

    return count;
    }
};