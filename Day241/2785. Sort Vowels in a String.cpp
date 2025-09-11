class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        vector<int> positions;
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isVowel(c)) {
                vowels.push_back(c);
                positions.push_back(i);
            }
        }
        
        sort(vowels.begin(), vowels.end());
        
        string t = s;
        for (int i = 0; i < positions.size(); i++) {
            t[positions[i]] = vowels[i];
        }
        
        return t;
    }
    
private:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    
};