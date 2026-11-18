class Solution {
public:
    int visIslands(int currRow, int currCol, vector<vector<char>>& grid,
                 vector<vector<int>>& vis) {
        vis[currRow][currCol] = 1;
        int n = grid.size(), m = grid[0].size();    
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for(int i = 0 ; i < 4; i++){
            int newRow = currRow + dr[i];
            int newCol = currCol + dc[i];
            if(newRow >= 0 && newRow < n && newCol >= 0  && newCol < m){
                if(grid[newRow][newCol] == '1' && vis[newRow][newCol] == 0){
                    visIslands(newRow, newCol, grid, vis);
                }
            }
        }
        return 0;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int noOfIslands = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                    visIslands(i, j, grid, visited);
                    noOfIslands += 1;
                }
            }
        }
        return noOfIslands;
    }
};
