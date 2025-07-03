class Solution {
public:
    char kthCharacter(int k) {
        int depth = 0;
        int length = 1;

        // Find the depth of the tree where the kth character lies
        while (length < k) {
            length *= 2;
            depth++;
        }
        int index = k - 1; // Convert to 0-based indexing
        int shift = 0;
        // Trace back from kth position to the original 'a'
        while (index > 0) {
            int half = length / 2;
            if (index >= half) {
                index -= half;
                shift++; // Because we applied "next char" operation
            }
            length /= 2;
        }
        // Starting from 'a', apply the shift number of next operations
        return 'a' + (shift % 26); // wrap around after 'z'
    }
};