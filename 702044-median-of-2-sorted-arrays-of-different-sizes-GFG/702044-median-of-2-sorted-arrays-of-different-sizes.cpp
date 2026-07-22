#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        int n1 = a.size();
        int n2 = b.size();

        // Always perform binary search on the smaller array for O(log(min(n1, n2))) complexity
        if (n1 > n2) return medianOf2(b, a);

        int low = 0, high = n1;
        int leftHalfSize = (n1 + n2 + 1) / 2;
        int totalSize = n1 + n2;

        while (low <= high) {
            int cut1 = low + (high - low) / 2;
            int cut2 = leftHalfSize - cut1;

            // Boundary conditions: edge values when cuts are at extremes
            int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];

            int r1 = (cut1 == n1) ? INT_MAX : a[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : b[cut2];

            // Valid partition found
            if (l1 <= r2 && l2 <= r1) {
                if (totalSize % 2 == 1) {
                    return max(l1, l2);
                } else {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
            }
            // Move left in array `a`
            else if (l1 > r2) {
                high = cut1 - 1;
            }
            // Move right in array `a`
            else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna