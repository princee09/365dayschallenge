class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        quickSelect(points, 0, points.size() - 1, k);
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
    
private:
    void quickSelect(vector<vector<int>>& points, int left, int right, int k) {
        if (left >= right) return;
        
        int pivotIndex = partition(points, left, right);
        
        if (pivotIndex == k) {
            return;
        } else if (pivotIndex < k) {
            quickSelect(points, pivotIndex + 1, right, k);
        } else {
            quickSelect(points, left, pivotIndex - 1, k);
        }
    }
    
    int partition(vector<vector<int>>& points, int left, int right) {
        vector<int> pivot = points[right];
        int pivotDist = getDistance(pivot);
        
        int i = left;
        for (int j = left; j < right; j++) {
            if (getDistance(points[j]) <= pivotDist) {
                swap(points[i], points[j]);
                i++;
            }
        }
        swap(points[i], points[right]);
        return i;
    }
    
    int getDistance(const vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }
};