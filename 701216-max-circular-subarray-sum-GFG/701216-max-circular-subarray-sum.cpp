#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int n = arr.size();
        
        // Variables for standard Kadane (Max Subarray Sum)
        int max_so_far = arr[0];
        int current_max = arr[0];
        
        // Variables for inverted Kadane (Min Subarray Sum)
        int min_so_far = arr[0];
        int current_min = arr[0];
        
        int total_sum = arr[0];
        
        for (int i = 1; i < n; i++) {
            total_sum += arr[i];
            
            // Standard Kadane's algorithm for Maximum Subarray
            current_max = max(arr[i], current_max + arr[i]);
            max_so_far = max(max_so_far, current_max);
            
            // Kadane's algorithm modified for Minimum Subarray
            current_min = min(arr[i], current_min + arr[i]);
            min_so_far = min(min_so_far, current_min);
        }
        
        // Edge Case: If all elements are negative, min_so_far will equal total_sum.
        // We cannot return 0 (total_sum - min_so_far) because the subarray must be non-empty.
        if (total_sum == min_so_far) {
            return max_so_far;
        }
        
        // Return the maximum of the wrapping and non-wrapping cases
        return max(max_so_far, total_sum - min_so_far);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna