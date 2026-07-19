class Solution {
  public:
    vector<bool> processQueries(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        
        // right[i] stores the furthest right index we can reach from i 
        // while the elements are non-decreasing (going uphill)
        right[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] <= arr[i + 1]) {
                right[i] = right[i + 1];
            } else {
                right[i] = i;
            }
        }
        
        // left[i] stores the furthest left index we can reach from i 
        // while the elements are non-increasing backwards (going downhill backwards)
        left[0] = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] <= arr[i - 1]) {
                left[i] = left[i - 1];
            } else {
                left[i] = i;
            }
        }
        
        vector<bool> ans;
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];
            
            // If the uphill walk from 'l' reaches or passes 
            // the point where the downhill walk to 'r' can start
            if (right[l] >= left[r]) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna