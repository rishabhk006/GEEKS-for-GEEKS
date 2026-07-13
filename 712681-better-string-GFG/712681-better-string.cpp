class Solution {
  public:
    long long countDistinct(string &s) {
        int n = s.size();

        vector<long long> dp(n + 1, 0);
        vector<int> last(256, -1);

        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            dp[i] = 2 * dp[i - 1];

            if (last[s[i - 1]] != -1)
                dp[i] -= dp[last[s[i - 1]] - 1];

            last[s[i - 1]] = i;
        }

        return dp[n];
    }

    string betterString(string &s1, string &s2) {
        return (countDistinct(s1) >= countDistinct(s2)) ? s1 : s2;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna