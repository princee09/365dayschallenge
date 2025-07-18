class Solution {
public:
    vector<int> maxSubseq(const vector<int>& nums, int t) {
        vector<int> stack;
        int drop = nums.size() - t;  // how many we can stil drop
        for (int x : nums) {
            while (drop > 0 && !stack.empty() && stack.back() < x) {
                stack.pop_back();
                --drop;
            }
            stack.push_back(x);
        }
        stack.resize(t);
        return stack;
    }
    vector<int> mergeMax(const vector<int>& a, const vector<int>& b) {
        vector<int> ans;
        int i = 0, j = 0, m = a.size(), n = b.size();
        while (i < m || j < n) {
            if (lexicographical_compare(a.begin() + i, a.end(),
                                        b.begin() + j, b.end())) {
                ans.push_back(b[j++]);
            } else {
                ans.push_back(a[i++]);
            }
        }
        return ans;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> best;
        // Try all splits take i from nums1 and k-i from nums2
        for (int i = max(0, k - n); i <= min(k, m); ++i) {
            auto subseq1 = maxSubseq(nums1, i);
            auto subseq2 = maxSubseq(nums2, k - i);
            auto candidate = mergeMax(subseq1, subseq2);
            if (candidate > best) best = move(candidate);
        }
        return best;
    }
};
