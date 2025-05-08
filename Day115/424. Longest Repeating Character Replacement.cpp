class Solution {
public:
    int characterReplacement(const string& s, int k) {
        vector<int> freq(26, 0);
        int maxFreq = 0;    // the count of the most frequent letter in the current window
        int left = 0;
        int best = 0;       // best window length seen so far

        for (int right = 0; right < s.size(); ++right) {
            // include s[right] in the window
            int idx = s[right] - 'A';
            freq[idx]++;
            maxFreq = max(maxFreq, freq[idx]);

            // if we need more than k replacements to make all letters = the most frequent one
            // shrink window from left
            while ((right - left + 1) - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
                // Note: we do NOT decrease maxFreq here,
                // it's okay because window only grows best‑case or shifts.
            }

            // update answer
            best = max(best, right - left + 1);
        }

        return best;
    }
};
