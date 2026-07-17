class Solution {
public:
    bool match(string wild, string pattern) {
        int n = wild.size(), m = pattern.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        for (int i = 1; i <= n; i++) {
            if (wild[i - 1] == '*')
                dp[i][0] = dp[i - 1][0];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (wild[i - 1] == pattern[j - 1] || wild[i - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (wild[i - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }

        return dp[n][m];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna