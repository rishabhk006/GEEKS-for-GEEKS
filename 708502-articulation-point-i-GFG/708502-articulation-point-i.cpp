class Solution {
  public:
    vector<int> tin, low, vis, ans;
    int timer = 0;

    void dfs(int u, int p, vector<int> adj[]) {
        vis[u] = 1;
        tin[u] = low[u] = timer++;

        int child = 0;

        for (int v : adj[u]) {
            if (v == p) continue;

            if (!vis[v]) {
                dfs(v, u, adj);
                low[u] = min(low[u], low[v]);

                if (p != -1 && low[v] >= tin[u])
                    ans.push_back(u);

                child++;
            } else {
                low[u] = min(low[u], tin[v]);
            }
        }

        if (p == -1 && child > 1)
            ans.push_back(u);
    }

    vector<int> articulationPoints(int V, vector<int> adj[]) {
        tin.assign(V, -1);
        low.assign(V, -1);
        vis.assign(V, 0);
        ans.clear();
        timer = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i])
                dfs(i, -1, adj);
        }

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        if (ans.empty())
            return {-1};

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna