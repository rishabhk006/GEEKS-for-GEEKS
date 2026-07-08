class Solution {
public:
    int minimumCostPath(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        
        // Min-heap storing elements as {cost, {r, c}}
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;
        
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            int current_cost = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            if (r == n - 1 && c == n - 1) return current_cost;
            if (current_cost > dist[r][c]) continue;
            
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    if (current_cost + grid[nr][nc] < dist[nr][nc]) {
                        dist[nr][nc] = current_cost + grid[nr][nc];
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }
        
        return dist[n - 1][n - 1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna