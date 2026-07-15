/*
Definition for Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
         vector<int> ans;
        if (!root) return ans;

        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int sz = q.size();
            vector<int> level(sz);

            for (int i = 0; i < sz; i++) {
                Node* cur = q.front();
                q.pop();

                int idx = leftToRight ? i : sz - 1 - i;
                level[idx] = cur->data;

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }

            for (int x : level)
                ans.push_back(x);

            leftToRight = !leftToRight;
        }

        return ans;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna