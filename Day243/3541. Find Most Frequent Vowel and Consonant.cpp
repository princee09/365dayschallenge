class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        int maxVowel = 0;
        int maxConsonant = 0;
        string vowels = "aeiou";

        for (auto& pair : freq) {
            char c = pair.first;
            int count = pair.second;
            if (vowels.find(c) != string::npos) {
                if (count > maxVowel) {
                    maxVowel = count;
                }
            } else {
                if (count > maxConsonant) {
                    maxConsonant = count;
                }
            }
        }

        return maxVowel + maxConsonant;
    }
};