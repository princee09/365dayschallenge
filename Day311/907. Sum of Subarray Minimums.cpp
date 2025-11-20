class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;
        long long result = 0;
        stack<int> st;
        vector<int> left(n), right(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        for (int i = 0; i < n; i++) {
            long long leftCount = i - left[i];
            long long rightCount = right[i] - i;
            result = (result + (arr[i] * leftCount * rightCount) % MOD) % MOD;
        }
        
        return result;
    }
};