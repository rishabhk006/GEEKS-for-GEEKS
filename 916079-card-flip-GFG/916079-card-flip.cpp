#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& front, vector<int>& back) {
        int n = front.size();
        const int INF = 1e9;
        
        // dp[mask][last_val] stores minimum inversions
        // last_val ranges from 0 to 30 (0 means no card placed yet)
        vector<vector<int>> dp(1 << n, vector<int>(31, INF));
        dp[0][0] = 0;
        
        for (int mask = 0; mask < (1 << n); ++mask) {
            int pos = __builtin_popcount(mask);
            
            for (int last_val = 0; last_val <= 30; ++last_val) {
                if (dp[mask][last_val] == INF) continue;
                
                for (int j = 0; j < n; ++j) {
                    if (!(mask & (1 << j))) {
                        // Determine visible side based on parity of position displacement
                        int val = ((pos % 2) == (j % 2)) ? front[j] : back[j];
                        
                        // Maintain non-decreasing order
                        if (val >= last_val) {
                            // Count elements in mask that are greater than j (inversions)
                            int mask_greater = mask & (~((1 << (j + 1)) - 1));
                            int inv = __builtin_popcount(mask_greater);
                            
                            int next_mask = mask | (1 << j);
                            dp[next_mask][val] = min(dp[next_mask][val], dp[mask][last_val] + inv);
                        }
                    }
                }
            }
        }
        
        int full_mask = (1 << n) - 1;
        int ans = INF;
        for (int v = 0; v <= 30; ++v) {
            ans = min(ans, dp[full_mask][v]);
        }
        
        return (ans == INF) ? -1 : ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna