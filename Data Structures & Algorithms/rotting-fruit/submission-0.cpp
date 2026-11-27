class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        int noOfRotten = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, {j, 0}});
                } else if (grid[i][j] == 1) {
                    noOfRotten += 1;
                }
            }
        }
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second.first;
            int time = q.front().second.second;
            q.pop();
            ans = max(ans, time);
            for (int i = 0; i < 4; i++) {
                int newR = x + dr[i];
                int newY = y + dc[i];
                if (newR >= 0 && newR < n && newY >= 0 && newY < m && grid[newR][newY] == 1) {
                    grid[newR][newY] = 2;
                    noOfRotten -= 1;
                    q.push({newR, {newY, time + 1}});
                }
            }
        }
        return noOfRotten == 0 ? ans : -1;
    }
};
