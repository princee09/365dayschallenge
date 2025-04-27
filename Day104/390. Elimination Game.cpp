class Solution {
public:
    int lastRemaining(int n) {
        bool leftToRight = true;
        int remaining = n;
        int head = 1;
        int step = 1;
        
        while (remaining > 1) {
            // if we're removing from left, or
            // removing from right when count is odd,
            // the head moves forward by step
            if (leftToRight || (remaining % 2 == 1)) {
                head += step;
            }
            // after each pass, half the numbers remain
            remaining /= 2;
            // the gap between adjacent remaining numbers doubles
            step *= 2;
            // alternate direction
            leftToRight = !leftToRight;
        }
        
        return head;
    }
};
