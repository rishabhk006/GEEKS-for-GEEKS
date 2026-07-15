class Solution {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        // code here
         if (n == 0) return 0;
        return (1LL << n) - 1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna