class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        const int START = 1950;
        const int END = 2050;
        const int RANGE = END - START + 1;
        vector<int> diff(RANGE + 1, 0); 

        for (const auto& log : logs) {
            int b = log[0] - START; 
            int d = log[1] - START; 
            diff[b] += 1;
            if (d >= 0 && d < (int)diff.size())
                diff[d] -= 1;
        }

        int maxPop = INT_MIN;
        int yearOfMax = START;
        int cur = 0;
        for (int i = 0; i < RANGE; ++i) {
            cur += diff[i];
            int year = START + i;
            if (cur > maxPop) {
                maxPop = cur;
                yearOfMax = year; 
            }
        }
        return yearOfMax;
    }
};