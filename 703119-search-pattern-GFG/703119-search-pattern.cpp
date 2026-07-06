class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        // code here
        int m = pat.size();
        int n = txt.size();
        vector<int> lps(m, 0);
        vector<int> result;

        // Precompute the LPS (Longest Proper Prefix which is also Suffix) array
        int len = 0;
        int i = 1;
        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // Perform the KMP search algorithm
        int txt_idx = 0;
        int pat_idx = 0;
        while (txt_idx < n) {
            if (pat[pat_idx] == txt[txt_idx]) {
                pat_idx++;
                txt_idx++;
            }

            if (pat_idx == m) {
                result.push_back(txt_idx - pat_idx);
                pat_idx = lps[pat_idx - 1];
            } else if (txt_idx < n && pat[pat_idx] != txt[txt_idx]) {
                if (pat_idx != 0) {
                    pat_idx = lps[pat_idx - 1];
                } else {
                    txt_idx++;
                }
            }
        }

        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna