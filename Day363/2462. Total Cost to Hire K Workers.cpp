class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leftHeap, rightHeap;
        int left = 0, right = n - 1;
        for (int i = 0; i < candidates && left <= right; i++) {
            leftHeap.push({costs[left], left});
            left++;
        }
        
        for (int i = 0; i < candidates && left <= right; i++) {
            rightHeap.push({costs[right], right});
            right--;
        }
        
        long long total = 0;
        
        for (int i = 0; i < k; i++) {
            if (!leftHeap.empty() && !rightHeap.empty()) {
                if (leftHeap.top().first < rightHeap.top().first) {
                    total += leftHeap.top().first;
                    leftHeap.pop();
                    if (left <= right) {
                        leftHeap.push({costs[left], left});
                        left++;
                    }
                } else if (leftHeap.top().first > rightHeap.top().first) {
                    total += rightHeap.top().first;
                    rightHeap.pop();
                    if (left <= right) {
                        rightHeap.push({costs[right], right});
                        right--;
                    }
                } else {
                    if (leftHeap.top().second <= rightHeap.top().second) {
                        total += leftHeap.top().first;
                        leftHeap.pop();
                        if (left <= right) {
                            leftHeap.push({costs[left], left});
                            left++;
                        }
                    } else {
                        total += rightHeap.top().first;
                        rightHeap.pop();
                        if (left <= right) {
                            rightHeap.push({costs[right], right});
                            right--;
                        }
                    }
                }
            } else if (!leftHeap.empty()) {
                total += leftHeap.top().first;
                leftHeap.pop();
                if (left <= right) {
                    leftHeap.push({costs[left], left});
                    left++;
                }
            } else if (!rightHeap.empty()) {
                total += rightHeap.top().first;
                rightHeap.pop();
                if (left <= right) {
                    rightHeap.push({costs[right], right});
                    right--;
                }
            }
        }
        
        return total;
    }
};