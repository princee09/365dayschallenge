class RecentCounter {
private:
    queue<int> q;

public:
    RecentCounter() {
        // Nothing to initialise here
    }

    int ping(int t) {
        q.push(t); // Add the new request
        // Remove requests older than t - 3000
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        return q.size(); // Remaining request are withn the last 3000 ms
    }
};
