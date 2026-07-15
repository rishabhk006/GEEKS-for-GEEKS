class Solution {
  public:
    unordered_set<long long> st;
    int dp[35];

    int solve(string &s, int i) {
        if (i == s.size()) return 0;
        if (dp[i] != -1) return dp[i];
        if (s[i] == '0') return dp[i] = 1e9;

        long long num = 0;
        int ans = 1e9;

        for (int j = i; j < s.size(); j++) {
            num = (num << 1) + (s[j] - '0');
            if (st.count(num))
                ans = min(ans, 1 + solve(s, j + 1));
        }

        return dp[i] = ans;
    }

    int cuts(string s) {
        st.clear();
        memset(dp, -1, sizeof(dp));

        long long x = 1;
        while (x <= (1LL << 30)) {
            st.insert(x);
            x *= 5;
        }

        int ans = solve(s, 0);
        return ans >= 1e9 ? -1 : ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna