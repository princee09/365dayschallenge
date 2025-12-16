class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> wordMap;
        vector<vector<int>> result;
        for (int i = 0; i < words.size(); i++) {
            wordMap[words[i]] = i;
        }
        for (int i = 0; i < words.size(); i++) {
            string word = words[i];
            int n = word.length();
            if (word.empty()) {
                for (int j = 0; j < words.size(); j++) {
                    if (i != j && isPalindrome(words[j])) {
                        result.push_back({i, j});
                        result.push_back({j, i});
                    }
                }
                continue;
            }   
            string reversedWord = word;
            reverse(reversedWord.begin(), reversedWord.end());
            if (wordMap.find(reversedWord) != wordMap.end()) {
                int j = wordMap[reversedWord];
                if (i != j) {
                    result.push_back({i, j});
                }
            }
            for (int k = 1; k < n; k++) {
                if (isPalindrome(word.substr(0, k))) {
                    string needed = word.substr(k);
                    reverse(needed.begin(), needed.end());
                    if (wordMap.find(needed) != wordMap.end()) {
                        int j = wordMap[needed];
                        if (i != j) {
                            result.push_back({j, i});
                        }
                    }
                }
                if (isPalindrome(word.substr(k))) {
                    string needed = word.substr(0, k);
                    reverse(needed.begin(), needed.end());
                    if (wordMap.find(needed) != wordMap.end()) {
                        int j = wordMap[needed];
                        if (i != j) {
                            result.push_back({i, j});
                        }
                    }
                }
            }
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        
        return result;
    }
    
private:
    bool isPalindrome(const string& s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
};