class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        
        int n = buses.size();
        int m = passengers.size();
        int j = 0; 
        int lastPassengerTime = -1;
        for (int i = 0; i < n; i++) {
            int currentCapacity = capacity;
            while (j < m && passengers[j] <= buses[i] && currentCapacity > 0) {
                lastPassengerTime = passengers[j];
                j++;
                currentCapacity--;
            }
            if (i == n - 1) {
                if (currentCapacity > 0) {
                    int time = buses[i];
                    while (binary_search(passengers.begin(), passengers.end(), time)) {
                        time--;
                    }
                    return time;
                } else {
                    int time = lastPassengerTime - 1;
                    while (binary_search(passengers.begin(), passengers.end(), time)) {
                        time--;
                    }
                    return time;
                }
            }
        }
        
        return -1; 
    }
};