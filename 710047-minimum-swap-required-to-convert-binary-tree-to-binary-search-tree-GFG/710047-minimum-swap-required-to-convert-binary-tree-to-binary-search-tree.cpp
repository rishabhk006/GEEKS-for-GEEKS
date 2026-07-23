#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  private:
    // Helper function to extract Inorder Traversal from complete binary tree array
    void getInorder(vector<int>& arr, vector<int>& inorder, int index) {
        if (index >= arr.size()) return;

        // 1. Visit Left Child (2 * index + 1)
        getInorder(arr, inorder, 2 * index + 1);

        // 2. Visit Root Node
        inorder.push_back(arr[index]);

        // 3. Visit Right Child (2 * index + 2)
        getInorder(arr, inorder, 2 * index + 2);
    }

  public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        vector<int> inorder;
        
        // Step 1: Extract Inorder Traversal
        getInorder(arr, inorder, 0);

        // Step 2: Pair elements with their initial indices
        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; i++) {
            vec[i] = {inorder[i], i};
        }

        // Step 3: Sort by values to know target positions
        sort(vec.begin(), vec.end());

        // Step 4: Count swaps by detecting permutation cycles
        vector<bool> visited(n, false);
        int totalSwaps = 0;

        for (int i = 0; i < n; i++) {
            // Skip if already visited or already in the correct sorted position
            if (visited[i] || vec[i].second == i) {
                continue;
            }

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = vec[j].second; // Move to the element's original position
                cycleSize++;
            }

            // A cycle of size C takes (C - 1) swaps
            if (cycleSize > 0) {
                totalSwaps += (cycleSize - 1);
            }
        }

        return totalSwaps;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna