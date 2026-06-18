class Solution {
public:

    int solve(int i, vector<int>& nums, vector<int>& dp) {

        if(i == 0) return nums[0];
        if(i < 0) return 0;

        if(dp[i] != -1)
            return dp[i];

        int pick = nums[i] + solve(i - 2, nums, dp);
        int notPick = solve(i - 1, nums, dp);

        return dp[i] = max(pick, notPick);
    }

    int helper(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n, -1);

        return solve(n - 1, nums, dp);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        // Edge Cases
        if(n == 1) return nums[0];

        vector<int> temp1(nums.begin(), nums.end() - 1);
        vector<int> temp2(nums.begin() + 1, nums.end());

        return max(helper(temp1), helper(temp2));
    }
};