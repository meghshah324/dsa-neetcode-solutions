class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>>q;
        int INFY = 2147483647;
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < m; j++){
                 if(grid[i][j] == 0){
                    q.push({i,j});
                 }
            }
        }
        while(!q.empty()){
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            for(int i = 0 ; i < 4; i++){
                int newRow = currRow + dr[i];
                int newCol = currCol + dc[i];
                if(newRow >= 0 && newRow < n && newCol >= 0  && newCol < m){
                    if(grid[newRow][newCol] == INFY){
                        grid[newRow][newCol] = grid[currRow][currCol] + 1;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
        return;   
    }
};
