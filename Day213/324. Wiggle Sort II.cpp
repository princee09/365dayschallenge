
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        auto mid = nums.begin() + n / 2;
        nth_element(nums.begin(), mid, nums.end());
        int median = *mid;
        auto index = [n](int i) {
            return (1 + 2 * i) % (n | 1);
        };
        int left = 0, i = 0, right = n - 1;
        while (i <= right) {
            if (nums[index(i)] > median) {
                swap(nums[index(left)], nums[index(i)]);
                left++;
                i++;
            } 
            else if (nums[index(i)] < median) {
                swap(nums[index(right)], nums[index(i)]);
                right--;
            } 
            else {
                i++;
            }
        }
    }
};