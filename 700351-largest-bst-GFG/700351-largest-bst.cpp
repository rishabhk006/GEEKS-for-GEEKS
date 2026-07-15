class Solution {
  public:
    struct Info {
        bool bst;
        int sz;
        int mn;
        int mx;
    };

    Info dfs(Node* root, int &ans) {
        if (!root)
            return {true, 0, INT_MAX, INT_MIN};

        Info l = dfs(root->left, ans);
        Info r = dfs(root->right, ans);

        if (l.bst && r.bst && root->data > l.mx && root->data < r.mn) {
            int s = l.sz + r.sz + 1;
            ans = max(ans, s);
            return {true, s, min(root->data, l.mn), max(root->data, r.mx)};
        }

        return {false, max(l.sz, r.sz), INT_MIN, INT_MAX};
    }

    int largestBst(Node *root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna