class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
         int n = start.size();

        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++)
            v.push_back({finish[i], start[i]});

        sort(v.begin(), v.end());

        int ans = 1;
        int lastFinish = v[0].first;

        for (int i = 1; i < n; i++) {
            if (v[i].second > lastFinish) {
                ans++;
                lastFinish = v[i].first;
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna