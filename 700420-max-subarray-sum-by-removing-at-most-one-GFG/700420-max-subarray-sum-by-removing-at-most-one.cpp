#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSumSubarray(std::vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return arr[0];

        int max_no_skip = arr[0];
        int max_one_skip = arr[0];
        int overall_max = arr[0];

        for (int i = 1; i < n; i++) {
            int prev_no_skip = max_no_skip;
            max_no_skip = std::max(arr[i], max_no_skip + arr[i]);
            max_one_skip = std::max(prev_no_skip, max_one_skip + arr[i]);
            overall_max = std::max({overall_max, max_no_skip, max_one_skip});
        }

        return overall_max;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna