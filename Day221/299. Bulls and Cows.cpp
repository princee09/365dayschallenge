class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        vector<int> countS(10, 0), countG(10, 0);  
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;  
            } else {
                countS[secret[i] - '0']++;
                countG[guess[i] - '0']++;
            }
        }
        
        for (int d = 0; d < 10; d++) {
            cows += min(countS[d], countG[d]);
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};