class Solution {
public:
    int magicalString(int n) {
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 1;
        if (n == 3)
            return 1;

        vector<int> s(n + 1);
        s[0] = 1;
        s[1] = 2;
        s[2] = 2;
        int head = 2;
        int tail = 3;
        int num = 1;
        int ones = 1;
        while (tail < n) {
            int times = s[head];
            for (int t = 0; t < times && tail < n; ++t) {
                s[tail++] = num;
                if (num == 1)
                    ++ones;
            }
            num = 3 - num;
            ++head;
        }
        return ones;
    }
};