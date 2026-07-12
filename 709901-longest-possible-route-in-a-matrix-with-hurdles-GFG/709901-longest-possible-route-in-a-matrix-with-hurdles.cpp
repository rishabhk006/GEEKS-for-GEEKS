class Solution {
  public:
    int ans = -1;
    int n, m;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(vector<vector<int>> &mat, int x, int y, int xd, int yd, int len) {
        if (x == xd && y == yd) {
            ans = max(ans, len);
            return;
        }

        mat[x][y] = 0;

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == 1)
                dfs(mat, nx, ny, xd, yd, len + 1);
        }

        mat[x][y] = 1;
    }

    int longestPath(vector<vector<int>> &mat, int xs, int ys, int xd, int yd) {
        n = mat.size();
        m = mat[0].size();

        if (mat[xs][ys] == 0 || mat[xd][yd] == 0)
            return -1;

        dfs(mat, xs, ys, xd, yd, 0);

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna