class Solution {
public:

    bool solve(int i, string& s,
               unordered_set<string>& st,
               vector<int>& dp) {

        // Base Case
        if(i == s.size())
            return true;

        if(dp[i] != -1)
            return dp[i];

        string temp = "";

        for(int j = i; j < s.size(); j++) {

            temp += s[j];

            if(st.find(temp) != st.end()) {

                if(solve(j + 1, s, st, dp))
                    return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> st(
            wordDict.begin(),
            wordDict.end()
        );

        vector<int> dp(s.size(), -1);

        return solve(0, s, st, dp);
    }
};