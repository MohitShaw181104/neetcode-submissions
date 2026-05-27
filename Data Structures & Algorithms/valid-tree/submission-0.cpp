class Solution {
public:
    bool dfs(int node,
             int parent,
             vector<vector<int>>& adj,
             vector<int>& vis) {

        vis[node] = 1;

        for(auto it : adj[node]) {

            // not visited
            if(!vis[it]) {

                if(dfs(it, node, adj, vis)) {
                    return true;
                }
            }

            // visited and not parent
            else if(it != parent) {

                return true;
            }
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!= n-1) return false;

        //now we will make adj node
        vector<vector<int>> adj(n);
        
        //now we will make edges
        for(auto it: edges){
            int u = it[0];
            int v= it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //now we will mark the vis nodes
        vector<int> vis(n, 0);

        if(dfs(0, -1, adj, vis)) {
            return false;
        }

        // check connected graph
        for(int i = 0; i < n; i++) {

            if(!vis[i]) {
                return false;
            }
        }

        return true;
    }
};