
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) 
            return 0;                // no primes < 2

        int count = 1;                // count the prime 2
        int half = n >> 1;            // we’ll represent only odd numbers: index i → num = 2*i + 1
        vector<bool> isPrime(half, true);

        // Sieve only odd i starting from 3
        // i = 2*k + 1  → index k = i>>1
        for (int i = 3; i * i < n; i += 2) {
            if (isPrime[i >> 1]) {
                // mark multiples of i, starting at i*i, step = 2*i (to stay on odds)
                for (int j = i * i; j < n; j += i << 1) {
                    isPrime[j >> 1] = false;
                }
            }
        }

        // Count remaining primes among odd numbers
        for (int k = 1; k < half; ++k) {
            if (isPrime[k]) 
                ++count;
        }
        return count;
    }
};
