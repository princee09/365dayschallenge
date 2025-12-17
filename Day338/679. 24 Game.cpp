class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return backtrack(nums);
    }
    
private:
    bool backtrack(vector<double>& nums) {
        if (nums.size() == 1) {
            return fabs(nums[0] - 24) < 1e-6;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i == j) continue;
                
                vector<double> newNums;
                for (int k = 0; k < nums.size(); k++) {
                    if (k != i && k != j) {
                        newNums.push_back(nums[k]);
                    }
                }
                
                for (int op = 0; op < 4; op++) {
                    if (op < 2 && i > j) continue;
                    
                    if (op == 0) newNums.push_back(nums[i] + nums[j]);
                    else if (op == 1) newNums.push_back(nums[i] * nums[j]);
                    else if (op == 2) newNums.push_back(nums[i] - nums[j]);
                    else if (op == 3) {
                        if (fabs(nums[j]) < 1e-6) continue;
                        newNums.push_back(nums[i] / nums[j]);
                    }
                    
                    if (backtrack(newNums)) return true;
                    newNums.pop_back();
                    if (op == 2) {
                        newNums.push_back(nums[j] - nums[i]);
                        if (backtrack(newNums)) return true;
                        newNums.pop_back();
                    } else if (op == 3) {
                        if (fabs(nums[i]) < 1e-6) continue;
                        newNums.push_back(nums[j] / nums[i]);
                        if (backtrack(newNums)) return true;
                        newNums.pop_back();
                    }
                }
            }
        }
        return false;
    }
};