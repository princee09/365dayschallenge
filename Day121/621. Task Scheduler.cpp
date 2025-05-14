class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Frequency count for each task A–Z
        int freq[26] = {0};
        for (char t : tasks) {
            freq[t - 'A']++;
        }
        // Find maximum frequency and how many tasks have that frequency
        int f_max = 0, count_max = 0;
        for (int f : freq) {
            if (f > f_max) {
                f_max = f;
                count_max = 1;
            } else if (f == f_max) {
                count_max++;
            }
        }
        // Compute the minimum intervals using the “frame” formula:
        // We have (f_max − 1) full groups, each of size (n + 1),
        // plus one last group where we place all the most frequent tasks.
        int part_count = f_max - 1;
        int part_length = n + 1;
        int empty_slots = part_count * part_length + count_max;
        
        // The answer is the maximum of total tasks length vs. the computed frame length
        return max((int)tasks.size(), empty_slots);
    }
};
