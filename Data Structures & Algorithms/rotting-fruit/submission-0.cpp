class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>, int>> q;

        vector<vector<int>> vis = grid;

        int fresh = 0;

        // store all rotten oranges in queue
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                // rotten orange
                if(grid[i][j] == 2) {

                    q.push({{i, j}, 0});
                }

                // count fresh oranges
                if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int time = 0;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        int cntFresh = 0;

        while(!q.empty()) {

            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;

            q.pop();

            time = max(time, t);

            for(int i = 0; i < 4; i++) {

                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                // valid fresh orange
                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   vis[nrow][ncol] == 1) {

                    vis[nrow][ncol] = 2;

                    q.push({{nrow, ncol}, t + 1});

                    cntFresh++;
                }
            }
        }

        // if some fresh oranges never rotted
        if(cntFresh != fresh) {
            return -1;
        }

        return time;
    }
};
