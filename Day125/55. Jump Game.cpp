class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;  // the farthest index we can reach so far
        
        for (int i = 0; i < nums.size(); ++i) {
            // If current index is beyond our maximum reachable, we’re stuck
            if (i > maxReach) 
                return false;
            
            // Update the farthest we can reach from here
            maxReach = max(maxReach, i + nums[i]);
            
            // If we can already reach or pass the last index, return true
            if (maxReach >= nums.size() - 1)
                return true;
        }
        
        // If we finish the loop without reaching the end, it’s not possible
        return false;
    }
};
