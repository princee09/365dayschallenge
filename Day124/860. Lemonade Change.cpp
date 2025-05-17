class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;  // count of $5 bills in hand
        int ten  = 0;  // count of $10 bills in hand
        
        for (int b : bills) {
            if (b == 5) {
                five++;
            }
            else if (b == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            }
            else { // b == 20
                // prefer giving 10 + 5 as change, else 5 + 5 + 5
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }
                else if (five >= 3) {
                    five -= 3;
                }
                else {
                    return false;
                }
            }
        }
        
        return true;
    }
};
