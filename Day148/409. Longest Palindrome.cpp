class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
    for (char c : s)
        freq[c]++;

    int length = 0;
    bool oddFound = false;

    for (auto& [ch, count] : freq) {
        if (count % 2 == 0)
            length += count;
        else {
            length += count - 1;
            oddFound = true;
        }
    }
    // Add 1 if there's any character with odd frequency (can go in the center)
    if (oddFound)
        length++;

    return length;
    }
};