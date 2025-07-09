class Solution {
public:
    int countSoldiers(const vector<int>& row) {
        int low = 0, high = row.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (row[mid] == 1)
                low = mid + 1;
            else
                high = mid;
        }
        return low; // Number of 1's
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> power; 
        for (int i = 0; i < mat.size(); ++i) {
            int soldiers = countSoldiers(mat[i]);
            power.push_back({soldiers, i});
        }
        sort(power.begin(), power.end());

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(power[i].second);
        }
        return result;
    }
};
