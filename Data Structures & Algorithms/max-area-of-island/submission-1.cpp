#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int dfs(int row, int col,
            int delRow[], int delCol[],
            vector<vector<int>>& grid,
            vector<vector<int>>& vis) {

        vis[row][col] = 1;

        int n = grid.size();
        int m = grid[0].size();

        // current cell contributes 1 area
        int area = 1;

        for (int i = 0; i < 4; i++) {

            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            // valid unvisited land
            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] &&
                grid[nrow][ncol] == 1) {

                area += dfs(nrow, ncol,
                            delRow, delCol,
                            grid, vis);
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int maxi = 0;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                // new island found
                if (!vis[i][j] && grid[i][j] == 1) {

                    int area = dfs(i, j,
                                   delRow, delCol,
                                   grid, vis);

                    maxi = max(maxi, area);
                }
            }
        }

        return maxi;
    }
};

// int main() {

//     vector<vector<int>> grid = {
//         {0,0,1,0,0},
//         {1,1,1,0,1},
//         {0,1,0,0,1},
//         {0,0,0,1,1}
//     };

//     Solution obj;

//     cout << "Maximum Island Area: "
//          << obj.maxAreaOfIsland(grid);

//     return 0;
// }