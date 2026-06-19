class Solution {
public:

    int solve(vector<int>& coins, int n, int amount,
              vector<vector<int>>& dp) {

        // Base Cases
        if(amount == 0)
            return 1;

        if(n == 0)
            return 0;

        if(dp[n][amount] != -1)
            return dp[n][amount];

        if(coins[n - 1] <= amount) {

            return dp[n][amount] =
                solve(coins, n, amount - coins[n - 1], dp)
                +
                solve(coins, n - 1, amount, dp);
        }

        return dp[n][amount] =
            solve(coins, n - 1, amount, dp);
    }

    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(amount + 1, -1)
        );

        return solve(coins, n, amount, dp);
    }
};