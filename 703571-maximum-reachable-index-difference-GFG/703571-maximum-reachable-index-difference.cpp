class Solution {
  public:
    int maxIndexDifference(string &s) {
        int n = s.size();
        
        // max_reach[c] stores the farthest index reachable by any instance 
        // of character 'a' + c seen so far to the right.
        vector<int> max_reach(26, -1);
        int max_diff = -1;

        for (int i = n - 1; i >= 0; --i) {
            int char_idx = s[i] - 'a';
            int farthest = i;

            // If the next character in alphabet exists to the right, jump to it
            if (char_idx + 1 < 26 && max_reach[char_idx + 1] != -1) {
                farthest = max(farthest, max_reach[char_idx + 1]);
            }

            // Update max_reach for current character
            max_reach[char_idx] = max(max_reach[char_idx], farthest);

            // If current character is 'a', calculate max difference
            if (s[i] == 'a') {
                max_diff = max(max_diff, farthest - i);
            }
        }

        return max_diff;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna