class Solution {
  public:
    int palPartition(string &s) {
        // code here
        int n = s.length();
        if (n <= 1) return 0;
        
        vector<vector<bool>> is_pal(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            is_pal[i][i] = true;
        }
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                is_pal[i][i + 1] = true;
            }
        }
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && is_pal[i + 1][j - 1]) {
                    is_pal[i][j] = true;
                }
            }
        }
        
        vector<int> cuts(n, 0);
        for (int i = 0; i < n; i++) {
            if (is_pal[0][i]) {
                cuts[i] = 0;
            } else {
                int min_cuts = INT_MAX;
                for (int j = 0; j < i; j++) {
                    if (is_pal[j + 1][i]) {
                        min_cuts = min(min_cuts, cuts[j] + 1);
                    }
                }
                cuts[i] = min_cuts;
            }
        }
        
        return cuts[n - 1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna