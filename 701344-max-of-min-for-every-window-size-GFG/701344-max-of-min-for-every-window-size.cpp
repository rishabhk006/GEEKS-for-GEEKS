#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
  public:
    // Method name set to maxOfMins to match driver expected signature
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> s;

        // Step 1: Find Previous Smaller Element (PSE) index
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }

        // Clear stack for reuse
        while (!s.empty()) s.pop();

        // Step 2: Find Next Smaller Element (NSE) index
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        // Step 3: Fill maximum of minimums for each window size
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;
            ans[len - 1] = max(ans[len - 1], arr[i]);
        }

        // Step 4: Propagate backward for smaller window sizes
        for (int i = n - 2; i >= 0; i--) {
            ans[i] = max(ans[i], ans[i + 1]);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna