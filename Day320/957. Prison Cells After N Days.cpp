class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        unordered_map<int, int> stateToDay;
        vector<vector<int>> dayToState;
        
        vector<int> current = cells;
        
        for (int day = 0; day < n; day++) {
            vector<int> next(8, 0);
            for (int i = 1; i < 7; i++) {
                next[i] = (current[i-1] == current[i+1]) ? 1 : 0;
            }
            int state = vectorToInt(next);
            if (stateToDay.find(state) != stateToDay.end()) {
                int cycleStart = stateToDay[state];
                int cycleLength = day - cycleStart;
                int remainingDays = (n - day - 1) % cycleLength;
                return dayToState[cycleStart + remainingDays];
            }
            
            stateToDay[state] = day;
            dayToState.push_back(next);
            current = next;
        }
        
        return current;
    }
    
private:
    int vectorToInt(const vector<int>& cells) {
        int state = 0;
        for (int i = 0; i < 8; i++) {
            state |= (cells[i] << i);
        }
        return state;
    }
};