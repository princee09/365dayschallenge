class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Quickselect: to seach kth largest we use index = n-k 
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
    
private:
    int quickSelect(vector<int>& a, int lo, int hi, int idx) {
        if (lo == hi) return a[lo];
        // Random pivot selection for better average performance
        int pivotIndex = lo + rand() % (hi - lo + 1);
        int pivot = a[pivotIndex];
        // 3-way partition (Dutch National Flag) [<pivot | ==pivot | >pivot]
        int i = lo, lt = lo, gt = hi;
        while (i <= gt) {
            if (a[i] < pivot) {
                swap(a[i++], a[lt++]);
            } else if (a[i] > pivot) {
                swap(a[i], a[gt--]);
            } else {
                i++;
            }
        }
        // now [lo..lt-1]<pivot, [lt..gt]==pivot, [gt+1..hi]>pivot
        
        if (idx < lt) {
            return quickSelect(a, lo, lt - 1, idx);
        } else if (idx > gt) {
            return quickSelect(a, gt + 1, hi, idx);
        } else {
            //idx in [lt..gt], i.e. pivot is the answer
            return pivot;
        }
    }
};
