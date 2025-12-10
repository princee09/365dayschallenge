class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int longest = 0;
        if (n < 3) return 0;
        int i = 1; 
        while (i < n - 1) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                int left = i - 1;
                int right = i + 1;
                while (left > 0 && arr[left] > arr[left - 1]) {
                    left--;
                }
                while (right < n - 1 && arr[right] > arr[right + 1]) {
                    right++;
                }
                int mountainLength = right - left + 1;
                longest = max(longest, mountainLength);
                i = right;
            } else {
                i++;
            }
        }
        
        return longest;
    }
};