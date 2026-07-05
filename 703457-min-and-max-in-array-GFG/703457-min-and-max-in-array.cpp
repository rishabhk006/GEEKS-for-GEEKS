class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        // code here
        long long min_val = arr[0];
        long long max_val = arr[0];
        
        for (size_t i = 1; i < arr.size(); i++) {
            if (arr[i] < min_val) {
                min_val = arr[i];
            } else if (arr[i] > max_val) {
                max_val = arr[i];
            }
        }
        
        return {min_val, max_val};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna