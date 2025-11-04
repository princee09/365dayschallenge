#include <bits/stdc++.h>
using namespace std;

class TopVotedCandidate {
private:
    vector<int> times;
    vector<int> leaders;

public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;
        leaders.resize(persons.size());
        
        unordered_map<int, int> voteCount;
        int currentLeader = -1;
        int maxVotes = 0;

        for (int i = 0; i < persons.size(); ++i) {
            voteCount[persons[i]]++;
            if (voteCount[persons[i]] >= maxVotes) {
                currentLeader = persons[i];
                maxVotes = voteCount[persons[i]];
            }
            leaders[i] = currentLeader;
        }
    }

    int q(int t) {
        int idx = upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        return leaders[idx];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
