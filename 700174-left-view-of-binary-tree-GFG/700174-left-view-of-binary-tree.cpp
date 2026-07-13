class Solution {
  public:
    vector<int> leftView(Node *root) {
        vector<int> ans;
        if (!root) return ans;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                Node* cur = q.front();
                q.pop();

                if (i == 0)
                    ans.push_back(cur->data);

                if (cur->left)
                    q.push(cur->left);

                if (cur->right)
                    q.push(cur->right);
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna