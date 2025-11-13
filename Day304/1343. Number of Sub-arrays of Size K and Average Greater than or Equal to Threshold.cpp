class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        int requiredSum = k * threshold;
        int currentSum = 0;
        for (int i = 0; i < k; i++) {
            currentSum += arr[i];
        }
        if (currentSum >= requiredSum) {
            count++;
        }
        for (int i = k; i < arr.size(); i++) {
            currentSum += arr[i] - arr[i - k];
            if (currentSum >= requiredSum) {
                count++;
            }
        }
        
        return count;
    }
};