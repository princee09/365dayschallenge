class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int countLess = 0;  
        int countEqual = 0; 
        
        for (int num : nums) {
            if (num < target) {
                countLess++;
            } else if (num == target) {
                countEqual++;
            }
        }
        
        vector<int> result;
        for (int i = 0; i < countEqual; i++) {
            result.push_back(countLess + i);
        }
        
        return result;
    }
};