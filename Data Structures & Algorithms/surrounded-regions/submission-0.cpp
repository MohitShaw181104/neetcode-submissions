class Solution {
public:

    void dfs(vector<vector<char>>& board,
             vector<vector<int>>& vis,
             int row, int col,
             int delRow[], int delCol[]) {

        vis[row][col] = 1;

        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < 4; i++) {

            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            // valid unvisited 'O'
            if(nrow >= 0 && nrow < n &&
               ncol >= 0 && ncol < m &&
               !vis[nrow][ncol] &&
               board[nrow][ncol] == 'O') {

                dfs(board, vis, nrow, ncol,
                    delRow, delCol);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // traverse first & last row
        for(int j = 0; j < m; j++) {

            // first row
            if(board[0][j] == 'O' && !vis[0][j]) {

                dfs(board, vis, 0, j,
                    delRow, delCol);
            }

            // last row
            if(board[n-1][j] == 'O' &&
               !vis[n-1][j]) {

                dfs(board, vis, n-1, j,
                    delRow, delCol);
            }
        }

        // traverse first & last column
        for(int i = 0; i < n; i++) {

            // first column
            if(board[i][0] == 'O' &&
               !vis[i][0]) {

                dfs(board, vis, i, 0,
                    delRow, delCol);
            }

            // last column
            if(board[i][m-1] == 'O' &&
               !vis[i][m-1]) {

                dfs(board, vis, i, m-1,
                    delRow, delCol);
            }
        }

        // convert remaining O -> X
        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(board[i][j] == 'O' &&
                   !vis[i][j]) {

                    board[i][j] = 'X';
                }
            }
        }
    }
};

// int main() {

//     vector<vector<char>> board = {
//         {'X','X','X','X'},
//         {'X','O','O','X'},
//         {'X','X','O','X'},
//         {'X','O','X','X'}
//     };

//     Solution obj;

//     obj.solve(board);

//     for(auto row : board) {

//         for(auto cell : row) {
//             cout << cell << " ";
//         }

//         cout << endl;
//     }

//     return 0;
// }
