class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        long double total = 1.0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            total *= (long double)nums[i];
        }
        long double target_sq = (long double)target * (long double)target;
        if(abs(total - target_sq) > 1e-9) {
            return false;
        }
        
        return solve(0, nums, target, 1);
    }
    
private:
    bool solve(int i, vector<int>& nums, long long target, long long p) {
        int n = nums.size();
        if(i >= n || p > target) {
            return false;
        }
        if(p == target) {
            return true;
        }
        return solve(i + 1, nums, target, p * nums[i]) || solve(i + 1, nums, target, p);
    }
};\