class Twitter {
    // user -> set of followees
    unordered_map<int, unordered_set<int>> follows;
    // user -> list of (timestamp, tweetId)
    unordered_map<int, vector<pair<int,int>>> tweets;
    // global timestamp
    int timeCounter;

public:
    Twitter() {
        timeCounter = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        if (!follows[userId].count(userId)) {
            follows[userId].insert(userId);
        }
        tweets[userId].push_back({timeCounter++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        using T = tuple<int,int,int,int>;
        auto cmp = [](const T &a, const T &b){
            return get<0>(a) < get<0>(b);
        };
        priority_queue<T, vector<T>, decltype(cmp)> pq(cmp);
    
        if (follows.count(userId)) {
            for (int fid : follows[userId]) {
                auto &tw = tweets[fid];
                if (!tw.empty()) {
                    int idx = tw.size() - 1;
                    pq.emplace(tw[idx].first, tw[idx].second, fid, idx);
                }
            }
        }
        while (!pq.empty() && res.size() < 10) {
            auto [ts, tid, uid, idx] = pq.top();
            pq.pop();
            res.push_back(tid);
            if (idx > 0) {
                auto &tw = tweets[uid];
                int nxt = idx - 1;
                pq.emplace(tw[nxt].first, tw[nxt].second, uid, nxt);
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (!follows[followerId].count(followerId)) {
            follows[followerId].insert(followerId);
        }
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followeeId != followerId && follows.count(followerId)) {
            follows[followerId].erase(followeeId);
        }
    }
};


/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */