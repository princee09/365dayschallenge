class Solution {
public:
    int differenceOfSums(int n, int m) {
        // Total sum from 1 to n using formula: n*(n+1)/2
        int totalSum = n * (n + 1) / 2;

        // Count of numbers divisible by m in range [1, n]
        int count = n / m;

        // Sum of numbers divisible by m using arithmetic progression:
        // m + 2m + 3m + ... + km = m * (1 + 2 + ... + k) = m * (k*(k+1)/2)
        int divisibleSum = m * (count * (count + 1)) / 2;

        // Subtracting divisible sum from total sum gives non-divisible sum
        int nonDivisibleSum = totalSum - divisibleSum;

        return nonDivisibleSum - divisibleSum;
    }
};
