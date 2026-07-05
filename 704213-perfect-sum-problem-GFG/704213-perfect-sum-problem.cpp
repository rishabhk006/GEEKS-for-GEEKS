class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int MOD = 1e9 + 7;
        
        // dp[j] stores the number of subsets that sum to j
        vector<int> dp(target + 1, 0);
        
        // Base case: There is 1 empty subset that sums up to 0
        dp[0] = 1;
        
        for (int i = 0; i < n; i++) {
            // Traverse backwards to avoid using the same element multiple times
            for (int j = target; j >= arr[i]; j--) {
                dp[j] = (dp[j] + dp[j - arr[i]]) % MOD;
            }
        }
        
        return dp[target];
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna