class Solution {
  public:
    int missingNum(vector<int>& arr) {
        int n = arr.size() + 1;
        long long total = 1LL * n * (n + 1) / 2;
        long long sum = 0;

        for (int x : arr)
            sum += x;

        return total - sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna