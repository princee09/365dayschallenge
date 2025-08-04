class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> cnt;
        int left = 0, result = 0;
        for (int right = 0; right < (int)fruits.size(); ++right) {
            cnt[fruits[right]]++;
            while (cnt.size() > 2) {
                if (--cnt[fruits[left]] == 0) {
                    cnt.erase(fruits[left]);
                }
                ++left;
            }
            result = max(result, right - left + 1);
        }
        
        return result;
    }
};