
class KthLargest {
private:
    int k;
    // min-heap to store the k largest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    // Constructor: initialize k and build heap from initial nums
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }

    // Add a new value and return the kth largest so far
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        // top of min-heap is the kth largest
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */