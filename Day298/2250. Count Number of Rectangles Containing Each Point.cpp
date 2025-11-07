class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> heights(101);
        for (auto& rect : rectangles) {
            int l = rect[0], h = rect[1];
            heights[h].push_back(l);
        }
        for (int h = 1; h <= 100; h++) {
            sort(heights[h].begin(), heights[h].end());
        }
        vector<int> result;
        for (auto& point : points) {
            int x = point[0], y = point[1];
            int count = 0;
            for (int h = y; h <= 100; h++) {
                if (heights[h].empty()) continue;
                auto& lengths = heights[h];
                int left = 0, right = lengths.size() - 1;
                int idx = lengths.size(); 
                
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (lengths[mid] >= x) {
                        idx = mid;
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                
                count += lengths.size() - idx;
            }
            
            result.push_back(count);
        }
        
        return result;
    }
};