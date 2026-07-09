class Solution {
  public:
    string reverseWords(string &s) {
        // code here
         vector<string> words;
        string temp;

        for (char c : s) {
            if (c == '.') {
                if (!temp.empty()) {
                    words.push_back(temp);
                    temp.clear();
                }
            } else {
                temp += c;
            }
        }

        if (!temp.empty())
            words.push_back(temp);

        reverse(words.begin(), words.end());

        string ans;

        for (int i = 0; i < words.size(); i++) {
            ans += words[i];
            if (i != words.size() - 1)
                ans += '.';
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna