class Solution {
  public:
    const int MOD = 1000000007;

    int minOperations(vector<int> &b) {
        int n = b.size();
        vector<int> vis(n, 0);

        vector<int> mx(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int len = 0;
                int cur = i;

                while (!vis[cur]) {
                    vis[cur] = 1;
                    cur = b[cur] - 1;
                    len++;
                }

                int x = len;
                for (int p = 2; p * p <= x; p++) {
                    int cnt = 0;
                    while (x % p == 0) {
                        x /= p;
                        cnt++;
                    }
                    mx[p] = max(mx[p], cnt);
                }
                if (x > 1)
                    mx[x] = max(mx[x], 1);
            }
        }

        long long ans = 1;

        for (int p = 2; p <= n; p++) {
            while (mx[p]--) {
                ans = (ans * p) % MOD;
            }
        }

        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna