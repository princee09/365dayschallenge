class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n);
        ugly[0] = 1;
        
        int k = primes.size();
        vector<int> pointers(k, 0);
        vector<long> values(k); 
        
        for (int i = 1; i < n; i++) {
            long nextUgly = LONG_MAX;
            for (int j = 0; j < k; j++) {
                values[j] = (long)ugly[pointers[j]] * primes[j];
                nextUgly = min(nextUgly, values[j]);
            }
            
            ugly[i] = (int)nextUgly;
            for (int j = 0; j < k; j++) {
                if (values[j] == nextUgly) {
                    pointers[j]++;
                }
            }
        }
        
        return ugly[n - 1];
    }
};