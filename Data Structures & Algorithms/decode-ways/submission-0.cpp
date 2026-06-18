class Solution {
public:

    int solve(int i, string& s, vector<int>& dp) {

        // Base Case
        if(i == s.size())
            return 1;

        // Invalid
        if(s[i] == '0')
            return 0;

        if(dp[i] != -1)
            return dp[i];

        // Take 1 digit
        int ways = solve(i + 1, s, dp);

        // Take 2 digits
        if(i + 1 < s.size() &&
           (s[i] == '1' ||
           (s[i] == '2' && s[i + 1] <= '6'))) {

            ways += solve(i + 2, s, dp);
        }

        return dp[i] = ways;
    }

    int numDecodings(string s) {

        int n = s.size();

        vector<int> dp(n, -1);

        return solve(0, s, dp);
    }
};