class Solution {
public:
    int findArea(int currRow, int currCol, vector<vector<int>>& grid,
                 vector<vector<int>>& vis) {
        vis[currRow][currCol] = 1;
        int n = grid.size(), m = grid[0].size();    
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        int currIslandArea = 1;
        for(int i = 0 ; i < 4; i++){
            int newRow = currRow + dr[i];
            int newCol = currCol + dc[i];
            if(newRow >= 0 && newRow < n && newCol >= 0  && newCol < m){
                if(grid[newRow][newCol] == 1 && vis[newRow][newCol] == 0){
                    currIslandArea += findArea(newRow, newCol, grid, vis);
                }
            }
        }
        return currIslandArea;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    int currIslandArea = findArea(i, j, grid, visited);
                    maxArea = max(maxArea, currIslandArea);
                }
            }
        }
        return maxArea;
    }
};