class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        
        while (k--) {
            int smallest = pq.top();
            pq.pop();
            pq.push(smallest + 1);
        }
        
        long long product = 1;
        const int MOD = 1e9 + 7;
        
        while (!pq.empty()) {
            product = (product * pq.top()) % MOD;
            pq.pop();
        }
        
        return product;
    }
};