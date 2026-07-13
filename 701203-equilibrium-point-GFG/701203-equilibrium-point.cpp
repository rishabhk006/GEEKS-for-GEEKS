class Solution {
  public:
    int findEquilibrium(vector<int> &arr) {
        long long total = 0;
        
        for (int x : arr)
            total += x;
        
        long long left = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            total -= arr[i];
            
            if (left == total)
                return i;
            
            left += arr[i];
        }
        
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna