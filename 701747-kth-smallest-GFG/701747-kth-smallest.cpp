#include <vector>
#include <queue>

class Solution {
public:
    int kthSmallest(std::vector<int>& arr, int k) {
        std::priority_queue<int> max_heap;

        for (int i = 0; i < arr.size(); i++) {
            max_heap.push(arr[i]);
            if (max_heap.size() > k) {
                max_heap.pop();
            }
        }

        return max_heap.top();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna