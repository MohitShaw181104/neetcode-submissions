class Solution {
public:

    string encode(vector<string>& strs) {

        string ans = "";

        for(int i = 0; i < strs.size(); i++) {
            ans += to_string(strs[i].size()) + "#" + strs[i];
        }

        return ans;
    }

    vector<string> decode(string s) {

        vector<string> ans;

        int i = 0;

        while(i < s.size()) {

            int j = i;

            while(s[j] != '#') {
                j++;
            }

            int len = stoi(s.substr(i, j - i));

            string word = s.substr(j + 1, len);

            ans.push_back(word);

            i = j + 1 + len;
        }

        return ans;
    }
};