class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int total = 0;
        for (int i = 0; i < points.size() - 1; ++i) {
            int dx = abs(points[i + 1][0] - points[i][0]);
            int dy = abs(points[i + 1][1] - points[i][1]);
            total += max(dx, dy);
        }
        return total;
    }
};