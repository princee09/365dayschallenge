class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double low = 0.0, high = 1.0;
        
        vector<int> res(2);
        
        while (low < high) {
            double mid = (low + high) / 2.0;
            int count = 0;
            double maxFrac = 0.0;
            int numerator = 0, denominator = 0;
            int j = 1;
            for (int i = 0; i < n - 1; i++) {
                while (j < n && arr[i] > mid * arr[j]) {
                    j++;
                }
                if (j == n) break;
                
                count += (n - j);
                
                double frac = static_cast<double>(arr[i]) / arr[j];
                if (frac > maxFrac) {
                    maxFrac = frac;
                    numerator = arr[i];
                    denominator = arr[j];
                }
            }
            
            if (count < k) {
                low = mid;
            } else if (count > k) {
                high = mid;
                res[0] = numerator;
                res[1] = denominator;
            } else {
                res[0] = numerator;
                res[1] = denominator;
                break;
            }
        }
        
        return res;
    }
};