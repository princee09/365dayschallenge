class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> oddIdx;
        oddIdx.reserve(n+2);
        // sentinel before start
        oddIdx.push_back(-1);
        // collect indices of odd elements
        for(int i = 0; i < n; i++){
            if(nums[i] & 1) 
                oddIdx.push_back(i);
        }
        // sentinel after end
        oddIdx.push_back(n);

        long long ans = 0;
        // for each window of k consecutive odds in oddIdx:
        // number of choices for left boundary = oddIdx[i] - oddIdx[i-1]
        // number of choices for right boundary = oddIdx[i+k] - oddIdx[i+k-1]
        for(int i = 1; i + k < (int)oddIdx.size(); i++){
            long long leftChoices  = oddIdx[i]   - oddIdx[i-1];
            long long rightChoices = oddIdx[i+k] - oddIdx[i+k-1];
            ans += leftChoices * rightChoices;
        }
        return ans;
    }
};
