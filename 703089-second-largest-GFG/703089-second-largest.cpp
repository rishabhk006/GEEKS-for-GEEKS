class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int first = -1, second = -1;

        for (int x : arr) {
            if (x > first) {
                second = first;
                first = x;
            }
            else if (x > second && x != first) {
                second = x;
            }
        }

        return second;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna