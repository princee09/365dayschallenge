class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int res = 1;
        
        for (int i = 0; i < n; i++) {
            long long prod = nums[i];
            long long g = nums[i];
            long long l = nums[i];    
            for (int j = i + 1; j < n; j++) {
                prod *= nums[j];
                g = gcd((long long)g, (long long)nums[j]);
                l = lcm((long long)l, (long long)nums[j]);
                
                if (prod == g * l) {
                    res = max(res, j - i + 1);
                }
                
                if (prod > 1000000000LL) break;
            }
        }
        return res;
    }
private:
    long long gcd(long long a, long long b) {
        while (b) {
            long long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
    
    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }
};