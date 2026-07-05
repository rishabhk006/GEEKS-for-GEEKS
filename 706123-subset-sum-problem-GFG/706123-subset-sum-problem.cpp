class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<bool> dp(sum + 1, false);
        
        // Base case: A sum of 0 is always possible with an empty subset
        dp[0] = true;
        
        for (int num : arr) {
            // Traverse backwards to avoid using the same element multiple times
            for (int j = sum; j >= num; j--) {
                if (dp[j - num]) {
                    dp[j] = true;
                }
            }
        }
        
        return dp[sum];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna