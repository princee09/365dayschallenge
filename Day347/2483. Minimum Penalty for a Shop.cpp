class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int totalY = 0;
        for (char c : customers) {
            if (c == 'Y') totalY++;
        }
        int minPenalty = totalY;  
        int bestHour = 0;
        int currentPenalty = totalY;
        for (int hour = 1; hour <= n; hour++) {
            if (customers[hour - 1] == 'N') {
                currentPenalty++;
            } 
            else if (customers[hour - 1] == 'Y') {
                currentPenalty--;
            }
            if (currentPenalty < minPenalty) {
                minPenalty = currentPenalty;
                bestHour = hour;
            }
        }
        
        return bestHour;
    }
};