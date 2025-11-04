#include <bits/stdc++.h>
using namespace std;

class SnapshotArray {
private:
    int snap_id;
    vector<vector<pair<int, int>>> history; 

public:
    SnapshotArray(int length) {
        snap_id = 0;
        history.resize(length);
        for (int i = 0; i < length; ++i)
            history[i].push_back({0, 0});
    }
    
    void set(int index, int val) {
        if (history[index].back().first == snap_id)
            history[index].back().second = val;
        else
            history[index].push_back({snap_id, val});
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int id) {
        auto &records = history[index];
        int l = 0, r = records.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (records[m].first <= id) l = m + 1;
            else r = m - 1;
        }
        return records[r].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
