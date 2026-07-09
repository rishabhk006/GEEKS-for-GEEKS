class Solution {
public:
    bool solve(Node* root, long long low, long long high) {
        if (root == NULL)
            return true;

        if (root->data <= low || root->data >= high)
            return false;

        return solve(root->left, low, root->data) &&
               solve(root->right, root->data, high);
    }

    bool isBST(Node* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna