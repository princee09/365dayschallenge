class FindSumPairs {
public:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freq; // frequency of nums2 elements

    FindSumPairs(vector<int>& n1, vector<int>& n2) {
        nums1 = n1;
        nums2 = n2;
        for (int num : nums2) {
            freq[num]++;
        }
    }
    
    void add(int index, int val) {
        int old_val = nums2[index];
        freq[old_val]--;              // remove old value count
        nums2[index] += val;
        freq[nums2[index]]++;         // add new value count
    }
    
    int count(int tot) {
        int result = 0;
        for (int a : nums1) {
            int b = tot - a;
            if (freq.count(b)) {
                result += freq[b];
            }
        }
        return result;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */