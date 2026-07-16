class Solution {
  private:
    int dp[10][100];

    int solve(int digits_left, int current_sum) {
        if (digits_left == 0) {
            return current_sum == 0 ? 1 : 0;
        }

        if (current_sum < 0) {
            return 0;
        }

        if (dp[digits_left][current_sum] != -1) {
            return dp[digits_left][current_sum];
        }

        int ways = 0;
        for (int digit = 0; digit <= 9; ++digit) {
            ways += solve(digits_left - 1, current_sum - digit);
        }

        return dp[digits_left][current_sum] = ways;
    }

  public:
    int countWays(int n, int sum) {
        if (sum < 1 || sum > 9 * n) {
            return -1;
        }

        if (n == 1) {
            return (sum >= 1 && sum <= 9) ? 1 : -1;
        }

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                dp[i][j] = -1;
            }
        }

        int total_ways = 0;
        for (int first_digit = 1; first_digit <= 9; ++first_digit) {
            total_ways += solve(n - 1, sum - first_digit);
        }

        return total_ways == 0 ? -1 : total_ways;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna