class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        long long total = 0;            
        for (int i = n - 1; i >= 0; --i) {
            total = (total + shifts[i]) % 26;          
            int newChar = (s[i] - 'a' + total) % 26;   
            s[i] = char('a' + newChar);                
        }
        return s;
    }
};