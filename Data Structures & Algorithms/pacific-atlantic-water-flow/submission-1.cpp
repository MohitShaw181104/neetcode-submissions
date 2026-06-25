class Solution {
public:

    void dfs(int row, int col,
             vector<vector<int>>& heights,
             vector<vector<int>>& vis,
             int delRow[], int delCol[]) {

        vis[row][col] = 1;

        int n = heights.size();
        int m = heights[0].size();

        for(int i = 0; i < 4; i++) {

            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            // valid cell + not visited
            // move only to greater/equal height
            if(nrow >= 0 && nrow < n &&
               ncol >= 0 && ncol < m &&
               !vis[nrow][ncol] &&
               heights[nrow][ncol] >= heights[row][col]) {

                dfs(nrow, ncol,
                    heights, vis,
                    delRow, delCol);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // Pacific Ocean
        // top row
        for(int j = 0; j < m; j++) {

            if(!pacific[0][j]) {
                dfs(0, j, heights,
                    pacific,
                    delRow, delCol);
            }
        }

        // left column
        for(int i = 0; i < n; i++) {

            if(!pacific[i][0]) {
                dfs(i, 0, heights,
                    pacific,
                    delRow, delCol);
            }
        }

        // Atlantic Ocean
        // bottom row
        for(int j = 0; j < m; j++) {

            if(!atlantic[n-1][j]) {
                dfs(n-1, j, heights,
                    atlantic,
                    delRow, delCol);
            }
        }

        // right column
        for(int i = 0; i < n; i++) {

            if(!atlantic[i][m-1]) {
                dfs(i, m-1, heights,
                    atlantic,
                    delRow, delCol);
            }
        }

        vector<vector<int>> ans;

        // cells reachable by BOTH oceans
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(pacific[i][j] &&
                   atlantic[i][j]) {

                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};