class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        // If we take all cards, just return their sum
        if (k == n) {
            int total = 0;
            for (int x : cardPoints) total += x;
            return total;
        }
        
        // Compute total sum of all cards
        int totalSum = 0;
        for (int x : cardPoints) totalSum += x;
        
        // We want to leave (n-k) cards unchosen in a contiguous block
        // Find the subarray of length (n-k) with the minimum sum
        int windowSize = n - k;
        int currSum = 0;
        // Initialize first window
        for (int i = 0; i < windowSize; ++i) {
            currSum += cardPoints[i];
        }
        int minSubarraySum = currSum;
        
        // Slide the window across the array
        for (int i = windowSize; i < n; ++i) {
            currSum += cardPoints[i] - cardPoints[i - windowSize];
            minSubarraySum = min(minSubarraySum, currSum);
        }
        
        // Maximum points = totalSum − minimum sum of the dropped window
        return totalSum - minSubarraySum;
    }
};
