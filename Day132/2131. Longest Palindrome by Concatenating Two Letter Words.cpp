class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> wordCount;
        int length = 0;
        bool hasMiddle = false;

        for (const string& word : words) {
            string rev = word;
            reverse(rev.begin(), rev.end());
            if (wordCount[rev] > 0) {
                // Pair found
                length += 4; // two words of 2 letters each
                wordCount[rev]--;
            } else {
                // Store the word for future pair
                wordCount[word]++;
            }
        }
        // Check for any word like "aa", "bb", etc. that can be in the middle
        for (auto& [word, count] : wordCount) {
            if (word[0] == word[1] && count > 0) {
                length += 2; // add one such word in the middle
                break;
            }
        }

        return length;
    }
};
