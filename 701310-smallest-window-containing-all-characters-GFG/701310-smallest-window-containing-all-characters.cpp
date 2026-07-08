class Solution {
  public:
    string minWindow(string &s, string &p) {
        // code here
        int n = s.length();
        int m = p.length();
        
        if (m > n) return "";
        
        vector<int> p_map(26, 0);
        vector<int> s_map(26, 0);
        
        for (char ch : p) {
            p_map[ch - 'a']++;
        }
        
        int count = 0;
        int min_len = INT_MAX;
        int start_idx = -1;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            int r_idx = s[right] - 'a';
            s_map[r_idx]++;
            
            if (p_map[r_idx] != 0 && s_map[r_idx] <= p_map[r_idx]) {
                count++;
            }
            
            if (count == m) {
                while (left <= right) {
                    int l_idx = s[left] - 'a';
                    if (p_map[l_idx] == 0 || s_map[l_idx] > p_map[l_idx]) {
                        s_map[l_idx]--;
                        left++;
                    } else {
                        break;
                    }
                }
                
                int len = right - left + 1;
                if (len < min_len) {
                    min_len = len;
                    start_idx = left;
                }
            }
        }
        
        if (start_idx == -1) return "";
        return s.substr(start_idx, min_len);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna