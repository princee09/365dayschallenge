class Solution {
public:
    string largestNumber(vector<int>& nums) {
         vector<string> A;
        A.reserve(nums.size());
        for (int x : nums) {
            A.push_back(to_string(x));
        }
        sort(A.begin(), A.end(), [](const string &a, const string &b) {
            return a + b > b + a;
        });
        if (A[0] == "0") return "0";

        string ans;
        ans.reserve(nums.size() * 10); 
        for (auto &s : A) {
            ans += s;
        }
        return ans;
    }
};