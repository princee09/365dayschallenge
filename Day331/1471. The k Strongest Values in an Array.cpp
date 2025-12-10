class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int m = arr[(n - 1) / 2];
        vector<int> result;
        int left = 0, right = n - 1;
        
        while (k > 0) {
            int diffLeft = abs(arr[left] - m);
            int diffRight = abs(arr[right] - m);
            
            if (diffRight > diffLeft) {
                result.push_back(arr[right]);
                right--;
            } else if (diffLeft > diffRight) {
                result.push_back(arr[left]);
                left++;
            } else {
                if (arr[right] > arr[left]) {
                    result.push_back(arr[right]);
                    right--;
                } else {
                    result.push_back(arr[left]);
                    left++;
                }
            }
            k--;
        }
        
        return result;
    }
};