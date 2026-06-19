class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        //vector<vector<int>>dp(n1+1, vector<int>(n2+1, 0));
        vector<int>dp(n2+1, 0);
        //for(int i=0; i<=n1; i++)dp[i][0] = i;
        for(int j=0; j<=n2; j++)dp[j] = j;

        for(int i=1; i<=n1; i++){
            vector<int>curr(n2+1, 0);
            curr[0] = i;
            for(int j=1; j<=n2; j++){
                if(word1[i-1] == word2[j-1]) curr[j] = dp[j-1];
                else curr[j] = 1 + min(dp[j-1], min(dp[j], curr[j-1]));
            }
            dp = curr;
        }
        return dp[n2];
    }
};