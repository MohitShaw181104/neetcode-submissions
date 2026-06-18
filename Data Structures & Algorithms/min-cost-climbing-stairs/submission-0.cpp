class Solution {
public:

    int solve(int n, vector<int>& cost, vector<int>& dp) {

        // Base cases
        if(n == 0) return cost[0];
        if(n == 1) return cost[1];

        if(dp[n] != -1)
            return dp[n];

        int op1 = solve(n - 1, cost, dp);
        int op2 = solve(n - 2, cost, dp);

        return dp[n] = cost[n] + min(op1, op2);
    }

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        vector<int> dp(n, -1);

        int ans = INT_MAX;

        ans = min(ans, solve(n - 1, cost, dp));
        ans = min(ans, solve(n - 2, cost, dp));

        return ans;
    }
};