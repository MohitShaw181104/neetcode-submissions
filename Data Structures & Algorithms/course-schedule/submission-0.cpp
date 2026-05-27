class Solution {
public:

    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {

        // adjacency list
        vector<int> adj[numCourses];

        // indegree array
        vector<int> indegree(numCourses, 0);

        // build graph
        for(auto it : prerequisites) {

            int u = it[1];
            int v = it[0];

            adj[u].push_back(v);

            indegree[v]++;
        }

        queue<int> q;

        // push nodes having indegree 0
        for(int i = 0; i < numCourses; i++) {

            if(indegree[i] == 0) {

                q.push(i);
            }
        }

        vector<int> topo;

        // BFS
        while(!q.empty()) {

            int node = q.front();

            q.pop();

            topo.push_back(node);

            for(auto it : adj[node]) {

                indegree[it]--;

                if(indegree[it] == 0) {

                    q.push(it);
                }
            }
        }

        // if topo contains all courses
        if(topo.size() == numCourses) {

            return true;
        }

        return false;
    }
};
