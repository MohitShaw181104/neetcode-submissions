class Solution {
    vector<vector<int>>dp;
    int f(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&vis){
        if(dp[i][j] != -1)return dp[i][j];
        vis[i][j] = 1;
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 1;
        int dr[4]= {-1,0,1,0};
        int dc[4]= {0,1,0,-1};
        for(int k =0;k < 4;k++){
            int nr = i+dr[k];
            int nc = j+dc[k];
            if((nr >= 0 && nr < n && nc >= 0 && nc < m) &&
             !vis[nr][nc] && matrix[nr][nc] > matrix[i][j]){
                ans = max(ans,1+f(nr,nc,matrix,vis));
            }
        }
        vis[i][j] = 0;
        return dp[i][j] = ans;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
       int n = matrix.size();
       int m = matrix[0].size();
       vector<vector<int>>vis(n,vector<int>(m,0));
       dp.resize(n,vector<int>(m,-1));
       int ans = 1;
       for(int i =0;i < n;i++){
        for(int j = 0;j < m;j++){
            ans = max(ans,f(i,j,matrix,vis));
        }
       }
       return ans; 
    }
};