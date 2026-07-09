class Solution {
public:
    bool areAnagrams(string& s1, string& s2) {
        if (s1.size() != s2.size())
            return false;

        vector<int> freq(26, 0);

        for (char c : s1)
            freq[c - 'a']++;

        for (char c : s2)
            freq[c - 'a']--;

        for (int x : freq) {
            if (x != 0)
                return false;
        }

        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna