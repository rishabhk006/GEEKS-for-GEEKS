#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int minDifference(vector<int>& arr) {
        int total_sum = 0;
        for (int num : arr) {
            total_sum += num;
        }

        int target = total_sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : arr) {
            for (int j = target; j >= num; --j) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        // Find the largest subset sum <= total_sum / 2
        for (int j = target; j >= 0; --j) {
            if (dp[j]) {
                return total_sum - 2 * j;
            }
        }

        return total_sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna