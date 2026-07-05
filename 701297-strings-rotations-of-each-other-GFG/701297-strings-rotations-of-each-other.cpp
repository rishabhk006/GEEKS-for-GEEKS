class Solution {
  public:
    bool areRotations(string &s1, string &s2) {
        // code here
        if (s1.length() != s2.length()) {
            return false;
        }
        
        // Concatenating s1 with itself contains all possible rotations of s1
        string concatenated = s1 + s1;
        
        // Check if s2 is a substring of the concatenated string
        return concatenated.find(s2) != string::npos;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna