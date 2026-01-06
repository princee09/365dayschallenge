class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = nums1.size(), n2 = nums2.size();
        int minX = INT_MAX;
        for (int i = 0; i < n1; i++) {
            for (int j = i + 1; j < n1; j++) {
                unordered_map<int, int> diffCount;
                int idx1 = 0, idx2 = 0;    
                while (idx1 < n1 && idx2 < n2) {
                    if (idx1 == i || idx1 == j) {
                        idx1++;
                        continue;
                    }
                    int diff = nums2[idx2] - nums1[idx1];
                    diffCount[diff]++;
                    idx1++;
                    idx2++;
                }
                if (idx2 == n2) {
                    for (auto& [d, cnt] : diffCount) {
                        if (cnt == n2) {
                            minX = min(minX, d);
                            break;
                        }
                    }
                }
            }
        }
        
        return minX;
    }
};