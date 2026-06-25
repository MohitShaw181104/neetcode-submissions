class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // State:
        // Queue stores {row, col, time}
        queue<pair<pair<int,int>, int>> q;

        int freshOranges = 0;

        // Initialization
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                // Push all rotten oranges
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                }

                // Count fresh oranges
                else if(grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        int time = 0;
        int rottenFresh = 0;

        // BFS Traversal
        while(!q.empty()) {

            int row = q.front().first.first;
            int col = q.front().first.second;
            int currTime = q.front().second;

            q.pop();

            time = max(time, currTime);

            // Explore 4 directions
            for(int i = 0; i < 4; i++) {

                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                // Valid fresh orange
                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   grid[nrow][ncol] == 1) {

                    // Mark rotten
                    grid[nrow][ncol] = 2;

                    rottenFresh++;

                    q.push({{nrow, ncol}, currTime + 1});
                }
            }
        }

        // Some fresh oranges couldn't rot
        if(rottenFresh != freshOranges) {
            return -1;
        }

        return time;
    }
};