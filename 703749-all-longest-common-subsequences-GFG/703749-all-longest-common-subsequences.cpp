#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
private:
    int n, m;
    vector<vector<int>> dp;
    vector<vector<set<string>>> memo;

    set<string> backtrack(int i, int j, const string& s1, const string& s2) {
        if (i == 0 || j == 0) {
            return {""};
        }
        
        if (!memo[i][j].empty()) {
            return memo[i][j];
        }

        set<string> current_results;

        if (s1[i - 1] == s2[j - 1]) {
            set<string> prev_results = backtrack(i - 1, j - 1, s1, s2);
            for (const string& str : prev_results) {
                current_results.insert(str + s1[i - 1]);
            }
        } else {
            if (dp[i - 1][j] == dp[i][j]) {
                set<string> left_results = backtrack(i - 1, j, s1, s2);
                current_results.insert(left_results.begin(), left_results.end());
            }
            if (dp[i][j - 1] == dp[i][j]) {
                set<string> right_results = backtrack(i, j - 1, s1, s2);
                current_results.insert(right_results.begin(), right_results.end());
            }
        }

        return memo[i][j] = current_results;
    }

public:
    vector<string> allLCS(string s1, string s2) {
        n = s1.length();
        m = s2.length();

        dp.assign(n + 1, vector<int>(m + 1, 0));
        memo.assign(n + 1, vector<set<string>>(m + 1));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // If no common characters are found, return an array containing an empty string
        if (dp[n][m] == 0) return {""};

        set<string> unique_lcs = backtrack(n, m, s1, s2);
        
        vector<string> result(unique_lcs.begin(), unique_lcs.end());
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna