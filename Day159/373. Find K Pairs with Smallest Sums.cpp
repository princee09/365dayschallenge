class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        vector<vector<int>> result;

        if (nums1.empty() || nums2.empty() || k == 0)
            return result;

        // Min-heap: (sum, index in nums1, index in nums2)
        auto compare = [&](const tuple<int, int, int>& a,
                           const tuple<int, int, int>& b) {
            return get<0>(a) > get<0>(b);
        };

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       decltype(compare)>
            minHeap(compare);

        // Push the first k pairs from nums1 with the first element of nums2
        for (int i = 0; i < nums1.size() && i < k; ++i) {
            minHeap.emplace(nums1[i] + nums2[0], i, 0);
        }

        while (!minHeap.empty() && result.size() < k) {
            auto [sum, i, j] = minHeap.top();
            minHeap.pop();
            result.push_back({nums1[i], nums2[j]});

            // Move to the next element in nums2
            if (j + 1 < nums2.size()) {
                minHeap.emplace(nums1[i] + nums2[j + 1], i, j + 1);
            }
        }

        return result;
    }
};