class Solution {
  public:
    int largest(vector<int> &arr) {
        int mx = arr[0];
        
        for (int x : arr)
            mx = max(mx, x);
        
        return mx;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna