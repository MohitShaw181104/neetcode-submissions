class Solution {
public:

    void islandsAndTreasure(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        // push all gates into queue
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 0) {

                    q.push({i, j});
                }
            }
        }

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // BFS
        while(!q.empty()) {

            int row = q.front().first;
            int col = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++) {

                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                // valid empty room
                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   grid[nrow][ncol] == 2147483647) {

                    // distance update
                    grid[nrow][ncol] =
                        grid[row][col] + 1;

                    q.push({nrow, ncol});
                }
            }
        }
    }
};
