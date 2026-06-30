#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        int candidate = -1;
        int count = 0;
        
        // Phase 1: Find a candidate
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                candidate = arr[i];
                count = 1;
            } else if (arr[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        // Phase 2: Verify the candidate
        int actual_count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == candidate) {
                actual_count++;
            }
        }
        
        if (actual_count > n / 2) {
            return candidate;
        }
        
        return -1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna