class Solution {
public:
    int largestArea(vector<int> &h) {
        stack<int> st;
        int ans = 0;

        for (int i = 0; i <= h.size(); i++) {
            while (!st.empty() && (i == h.size() || h[st.top()] >= h[i])) {
                int height = h[st.top()];
                st.pop();

                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                ans = max(ans, height * width);
            }
            st.push(i);
        }

        return ans;
    }

    int maxArea(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> h(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0)
                    h[j] = 0;
                else
                    h[j] += 1;
            }

            ans = max(ans, largestArea(h));
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna