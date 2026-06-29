class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int curr = arr[0];
        int maxi = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            curr = max(arr[i], curr + arr[i]);
            maxi = max(maxi, curr);
        }

        return maxi;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna