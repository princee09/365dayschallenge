class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) continue;
            
            int slow = i;
            int fast = i;
            while (true) {
                slow = getNext(nums, slow);
                fast = getNext(nums, getNext(nums, fast));
                if (slow == fast) break;
            }
            
            if (slow == getNext(nums, slow)) {
                nums[slow] = 0;
                continue;
            }
            
            int dir = nums[slow] > 0 ? 1 : -1;
            int curr = slow;
            bool valid = true;
            do {
                if (nums[curr] * dir <= 0) {
                    valid = false;
                    break;
                }
                int next = getNext(nums, curr);
                nums[curr] = 0;
                curr = next;
            } while (curr != slow);
            
            if (valid) return true;
        }
        return false;
    }
    
private:
    int getNext(vector<int>& nums, int idx) {
        int n = nums.size();
        int next = (idx + nums[idx]) % n;
        if (next < 0) next += n;
        return next;
    }
};