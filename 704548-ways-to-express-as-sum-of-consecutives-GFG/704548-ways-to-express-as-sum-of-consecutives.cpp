class Solution {
  public:
    int getCount(int n) {
        // code here
        int ans = 0;

        for (int k = 2; k * (k - 1) / 2 < n; k++) {
            int rem = n - k * (k - 1) / 2;

            if (rem % k == 0)
                ans++;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna