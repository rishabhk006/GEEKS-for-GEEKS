class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &path) {
        vis[node] = 1;
        path[node] = 1;

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                if (dfs(nei, adj, vis, path))
                    return true;
            } else if (path[nei]) {
                return true;
            }
        }

        path[node] = 0;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);

        for (auto &e : edges)
            adj[e[0]].push_back(e[1]);

        vector<int> vis(V, 0), path(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i] && dfs(i, adj, vis, path))
                return true;
        }

        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna