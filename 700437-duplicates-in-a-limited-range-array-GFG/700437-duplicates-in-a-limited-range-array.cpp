#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int> duplicates;
        
        for (int i = 0; i < arr.size(); i++) {
            int idx = abs(arr[i]) - 1;
            
            if (arr[idx] < 0) {
                duplicates.push_back(idx + 1);
            } else {
                arr[idx] = -arr[idx];
            }
        }
        
        return duplicates;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna