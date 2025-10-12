class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> result;
        vector<int> freq(101, 0);
        for (int i = 0; i < k; i++) {
            if (nums[i] < 0) {
                freq[nums[i] + 50]++;
            }
        }
        result.push_back(findXthSmallest(freq, x));
        
        for (int i = k; i < n; i++) {
            if (nums[i - k] < 0) {
                freq[nums[i - k] + 50]--;
            }
            if (nums[i] < 0) {
                freq[nums[i] + 50]++;
            }
            
            result.push_back(findXthSmallest(freq, x));
        }
        
        return result;
    }
    
private:
    int findXthSmallest(vector<int>& freq, int x) {
        int count = 0;
        
        for (int num = -50; num < 0; num++) {
            int idx = num + 50;
            count += freq[idx];
            
            if (count >= x) {
                return num;
            }
        }
        
        return 0; 
    }
};