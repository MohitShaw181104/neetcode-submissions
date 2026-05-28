class Solution {
public:

    string foreignDictionary(vector<string>& words) {

        vector<int> adj[26];

        vector<int> indegree(26, 0);

        vector<int> present(26, 0);

        // mark existing characters
        for(auto word : words) {

            for(auto ch : word) {

                present[ch - 'a'] = 1;
            }
        }

        // build graph
        for(int i = 0; i < words.size() - 1; i++) {

            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.size(), s2.size());

            bool found = false;

            for(int j = 0; j < len; j++) {

                // first different character
                if(s1[j] != s2[j]) {

                    int u = s1[j] - 'a';
                    int v = s2[j] - 'a';

                    adj[u].push_back(v);

                    indegree[v]++;

                    found = true;

                    break;
                }
            }

            // invalid case
            // abc before ab
            if(!found && s1.size() > s2.size()) {

                return "";
            }
        }

        queue<int> q;

        // push indegree 0 chars
        for(int i = 0; i < 26; i++) {

            if(present[i] &&
               indegree[i] == 0) {

                q.push(i);
            }
        }

        string ans = "";

        // topo sort BFS
        while(!q.empty()) {

            int node = q.front();

            q.pop();

            ans += char(node + 'a');

            for(auto it : adj[node]) {

                indegree[it]--;

                if(indegree[it] == 0) {

                    q.push(it);
                }
            }
        }

        // count total chars
        int total = 0;

        for(int i = 0; i < 26; i++) {

            if(present[i]) {
                total++;
            }
        }

        // cycle exists
        if(ans.size() != total) {

            return "";
        }

        return ans;
    }
};