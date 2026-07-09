class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
         vector<vector<int>> adj(V);
        
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<int> vis(V, 0);
        
        for (int i = 0; i < V; i++) {
            if (vis[i]) continue;
            
            queue<pair<int, int>> q;
            q.push({i, -1});
            vis[i] = 1;
            
            while (!q.empty()) {
                auto [node, parent] = q.front();
                q.pop();
                
                for (int nei : adj[node]) {
                    if (!vis[nei]) {
                        vis[nei] = 1;
                        q.push({nei, node});
                    } else if (nei != parent) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna