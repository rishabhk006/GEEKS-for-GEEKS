class Solution {
  public:
    string findOrder(vector<string> &words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> in_degree;

        for (const string &word : words) {
            for (char c : word) {
                if (in_degree.find(c) == in_degree.end()) {
                    in_degree[c] = 0;
                }
            }
        }

        int n = words.size();
        for (int i = 0; i < n - 1; i++) {
            const string &w1 = words[i];
            const string &w2 = words[i + 1];
            int len = min(w1.length(), w2.length());
            bool found_difference = false;

            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    if (adj[w1[j]].find(w2[j]) == adj[w1[j]].end()) {
                        adj[w1[j]].insert(w2[j]);
                        in_degree[w2[j]]++;
                    }
                    found_difference = true;
                    break;
                }
            }

            if (!found_difference && w1.length() > w2.length()) {
                return "";
            }
        }

        queue<char> q;
        for (auto const& p : in_degree) {
            if (p.second == 0) {
                q.push(p.first);
            }
        }

        string order = "";
        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            order += curr;

            for (char neighbor : adj[curr]) {
                in_degree[neighbor]--;
                if (in_degree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        if (order.length() < in_degree.size()) {
            return "";
        }

        return order;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna