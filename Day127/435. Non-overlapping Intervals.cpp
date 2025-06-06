class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Sort intervals based on their end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 0;
        int lastEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < lastEnd) {
                // Overlapping, need to remove this interval
                count++;
            } else {
                // No overlap, update lastEnd
                lastEnd = intervals[i][1];
            }
        }

        return count;
    }
};