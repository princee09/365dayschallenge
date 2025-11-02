class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        
        int n = tiles.size();
        int left = 0, right = 0;
        int cover = 0, maxCover = 0;
        
        while (right < n && maxCover < carpetLen) {
            int start = tiles[left][0];
            int end = start + carpetLen - 1;
            if (tiles[right][1] <= end) {
                cover += tiles[right][1] - tiles[right][0] + 1;
                maxCover = max(maxCover, cover);
                right++;
            } else {
                int partial = max(0, end - tiles[right][0] + 1);
                maxCover = max(maxCover, cover + partial);
                cover -= tiles[left][1] - tiles[left][0] + 1;
                left++;
            }
        }
        
        return min(maxCover, carpetLen);
    }
};\