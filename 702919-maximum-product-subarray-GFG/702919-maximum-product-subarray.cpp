class Solution {
  public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        
        // Use double to completely prevent integer overflow during intermediate multiplications
        double max_prod = arr[0];
        double prefix = 0;
        double suffix = 0;
        
        for (int i = 0; i < n; i++) {
            // Reset to current element if previous product became 0
            prefix = (prefix == 0) ? arr[i] : prefix * arr[i];
            suffix = (suffix == 0) ? arr[n - 1 - i] : suffix * arr[n - 1 - i];
            
            if (prefix > max_prod) max_prod = prefix;
            if (suffix > max_prod) max_prod = suffix;
        }
        
        return (int)max_prod;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna