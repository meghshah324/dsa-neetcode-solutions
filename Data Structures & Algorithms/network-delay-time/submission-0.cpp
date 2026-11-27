class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];
            adj[u].push_back({v, wt});
        }
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        int minTime = INT_MIN;
        while (!pq.empty()) {
            int node = pq.top().second;
            int currDist = pq.top().first;
            pq.pop();
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int time = it.second;
                if (dist[adjNode] > time + currDist) {
                    dist[adjNode] = time + currDist;
                    pq.push({time + currDist, adjNode});
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if(dist[i] == INT_MAX) return -1;
            minTime = max(minTime, dist[i]);
        }
        return minTime;
    }
};
