class Solution {
  public:
    int subseqCount(string &txt, string &pat) {
        // code here
         int n = txt.size(), m = pat.size();
        
        vector<long long> dp(m + 1, 0);
        dp[0] = 1;
        
        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                if (txt[i] == pat[j])
                    dp[j + 1] += dp[j];
            }
        }
        
        return dp[m];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna