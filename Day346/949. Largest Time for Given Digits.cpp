class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        string result = "";
        int maxTime = -1;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (j == i) continue;
                for (int k = 0; k < 4; k++) {
                    if (k == i || k == j) continue;
                    int l = 6 - i - j - k; 
                    int hours = arr[i] * 10 + arr[j];
                    int minutes = arr[k] * 10 + arr[l];
                    if (hours < 24 && minutes < 60) {
                        int totalMinutes = hours * 60 + minutes;
                        if (totalMinutes > maxTime) {
                            maxTime = totalMinutes;
                            result = formatTime(hours, minutes);
                        }
                    }
                }
            }
        }
        
        return result;
    }
private:
    string formatTime(int hours, int minutes) {
        char buffer[6];
        sprintf(buffer, "%02d:%02d", hours, minutes);
        return string(buffer);
    }
};