class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        vector<int> first_idx(26, -1);
        int max_gap = -1;
        
        for (int i = 0; i < s.length(); i++) {
            int char_val = s[i] - 'a';
            if (first_idx[char_val] == -1) {
                first_idx[char_val] = i;
            } else {
                max_gap = max(max_gap, i - first_idx[char_val] - 1);
            }
        }
        
        return max_gap;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna