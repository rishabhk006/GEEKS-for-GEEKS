#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool divisibleByK(vector<int>& arr, int k) {
        if (arr.size() >= k) {
            return true;
        }

        vector<bool> dp(k, false);

        for (int num : arr) {
            vector<bool> next_dp = dp;
            
            int current_rem = num % k;
            next_dp[current_rem] = true;

            for (int r = 0; r < k; r++) {
                if (dp[r]) {
                    next_dp[(r + current_rem) % k] = true;
                }
            }

            dp = next_dp;

            if (dp[0]) {
                return true;
            }
        }

        return dp[0];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna