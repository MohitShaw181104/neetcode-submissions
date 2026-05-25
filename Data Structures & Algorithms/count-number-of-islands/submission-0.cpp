class Solution {
public:
    
    void dfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& vis, int delRow[], int delCol[]) {
        
        vis[row][col] = 1;

        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            // Check bounds + unvisited land
            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] &&
                grid[nrow][ncol] == '1') {

                dfs(nrow, ncol, grid, vis, delRow, delCol);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // Start DFS for every unvisited land cell
                if (!vis[i][j] && grid[i][j] == '1') {
                    cnt++;
                    dfs(i, j, grid, vis, delRow, delCol);
                }
            }
        }

        return cnt;
    }
};