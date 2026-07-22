#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDeletions(vector<int>& arr) {
        int n = arr.size();
        vector<int> tails;

        for (int x : arr) {
            // Find the first element in tails that is >= x
            auto it = lower_bound(tails.begin(), tails.end(), x);

            if (it == tails.end()) {
                // x is strictly greater than all elements in tails
                tails.push_back(x);
            } else {
                // Replace the element to keep tail values as small as possible
                *it = x;
            }
        }

        // LIS length is tails.size()
        int lisLength = tails.size();

        return n - lisLength;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna