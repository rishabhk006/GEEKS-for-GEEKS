class Solution {
  public:
    int maxProduct(vector<int> arr) {
        // code here
        sort(arr.begin(), arr.end());

        int n = arr.size();

        int prod1 = arr[n - 1] * arr[n - 2] * arr[n - 3];
        int prod2 = arr[0] * arr[1] * arr[n - 1];

        return max(prod1, prod2);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna