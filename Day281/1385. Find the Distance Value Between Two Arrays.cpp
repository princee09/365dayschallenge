class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int count = 0;
        
        for (int num : arr1) {
            if (!hasCloseElement(arr2, num, d)) {
                count++;
            }
        }
        
        return count;
    }
    
private:
    bool hasCloseElement(vector<int>& arr, int target, int d) {
        int left = 0, right = arr.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (abs(arr[mid] - target) <= d) {
                return true;
            }
            
            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};