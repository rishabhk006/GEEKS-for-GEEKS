class Solution {
  public:
    vector<string> ans;
    int n;

    void dfs(int i, int j, vector<vector<int>> &maze, vector<vector<int>> &vis, string &path) {
        if (i == n - 1 && j == n - 1) {
            ans.push_back(path);
            return;
        }

        vis[i][j] = 1;

        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, -1, 1, 0};
        char dir[] = {'D', 'L', 'R', 'U'};

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && y >= 0 && x < n && y < n &&
                maze[x][y] == 1 && !vis[x][y]) {
                path.push_back(dir[k]);
                dfs(x, y, maze, vis, path);
                path.pop_back();
            }
        }

        vis[i][j] = 0;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        ans.clear();
        n = maze.size();

        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return ans;

        vector<vector<int>> vis(n, vector<int>(n, 0));
        string path = "";

        dfs(0, 0, maze, vis, path);

        sort(ans.begin(), ans.end());
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna