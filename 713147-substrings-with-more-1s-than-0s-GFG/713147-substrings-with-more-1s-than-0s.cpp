class Solution {
  public:
    int countSubstring(string s) {
        int n = s.length();
        
        // The maximum possible prefix sum is n, and the minimum is -n.
        // We use an offset of 'n' to safely map negative prefix sums to valid array indices.
        int offset = n;
        vector<int> freq(2 * n + 1, 0);
        
        // An initial prefix sum of 0 exists before reading any character
        freq[0 + offset] = 1;
        
        int total_substrings = 0;
        int current_prefix_sum = 0;
        int current_valid_count = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                // Moving from current_prefix_sum to (current_prefix_sum + 1):
                // All previous subsegments that were valid for 'current_prefix_sum' 
                // remain valid, PLUS the elements that had exactly the value 'current_prefix_sum'.
                current_valid_count += freq[current_prefix_sum + offset];
                current_prefix_sum++;
            } else {
                // Moving from current_prefix_sum to (current_prefix_sum - 1):
                // We lose the valid pairs that had a prefix sum equal to (current_prefix_sum - 1).
                current_prefix_sum--;
                current_valid_count -= freq[current_prefix_sum + offset];
            }
            
            total_substrings += current_valid_count;
            freq[current_prefix_sum + offset]++;
        }
        
        return total_substrings;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna