#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minChar(string& s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());

        // Create combined string with a non-alphabet separator
        string temp = s + "#" + rev_s;
        int n = temp.length();

        // Compute KMP LPS (Longest Prefix Suffix) array
        vector<int> lps(n, 0);
        for (int i = 1; i < n; ++i) {
            int j = lps[i - 1];
            while (j > 0 && temp[i] != temp[j]) {
                j = lps[j - 1];
            }
            if (temp[i] == temp[j]) {
                j++;
            }
            lps[i] = j;
        }

        // Longest palindromic prefix length is the last value in LPS array
        int longestPalindromicPrefix = lps.back();

        return s.length() - longestPalindromicPrefix;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna