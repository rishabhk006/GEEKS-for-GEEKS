#include <vector>
#include <algorithm>

class Solution {
public:
    int getMinDiff(std::vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 1) return 0;

        std::sort(arr.begin(), arr.end());

        int initial_diff = arr[n - 1] - arr[0];
        int ans = initial_diff;

        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;

        for (int i = 0; i < n - 1; i++) {
            int min_height = std::min(smallest, arr[i + 1] - k);
            int max_height = std::max(largest, arr[i] + k);

            if (min_height < 0) continue;

            ans = std::min(ans, max_height - min_height);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna