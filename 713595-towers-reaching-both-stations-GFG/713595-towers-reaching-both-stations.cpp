class Solution {
private:
    void dfs(int r, int c, vector<vector<bool>>& visited, const vector<vector<int>>& mat, int n, int m) {
        visited[r][c] = true;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc]) {
                if (mat[nr][nc] >= mat[r][c]) {
                    dfs(nr, nc, visited, mat, n, m);
                }
            }
        }
    }

public:
    int countCoordinates(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return 0;
        
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<bool>> reachableP(n, vector<bool>(m, false));
        vector<vector<bool>> reachableQ(n, vector<bool>(m, false));
        
        for (int j = 0; j < m; j++) dfs(0, j, reachableP, mat, n, m);
        for (int i = 0; i < n; i++) dfs(i, 0, reachableP, mat, n, m);
        
        for (int j = 0; j < m; j++) dfs(n - 1, j, reachableQ, mat, n, m);
        for (int i = 0; i < n; i++) dfs(i, m - 1, reachableQ, mat, n, m);
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (reachableP[i][j] && reachableQ[i][j]) {
                    count++;
                }
            }
        }
        
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna