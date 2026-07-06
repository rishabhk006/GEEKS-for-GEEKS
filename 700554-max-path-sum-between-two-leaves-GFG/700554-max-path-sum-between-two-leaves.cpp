class Solution {
  private:
    int maxPathSumUtil(Node* root, int &max_sum) {
        if (!root) return 0;
        
        // If it's a leaf node, return its data
        if (!root->left && !root->right) {
            return root->data;
        }
        
        // Compute maximum path sum in left and right subtrees
        int left_sum = maxPathSumUtil(root->left, max_sum);
        int right_sum = maxPathSumUtil(root->right, max_sum);
        
        // If the current node has both left and right children, it can form a complete path between two leaves
        if (root->left && root->right) {
            max_sum = max(max_sum, left_sum + right_sum + root->data);
            return max(left_sum, right_sum) + root->data;
        }
        
        // If one child is missing, return the path sum passing through the existing child
        return (root->left ? left_sum : right_sum) + root->data;
    }

  public:
    int maxPathSum(Node* root) {
        int max_sum = INT_MIN;
        int val = maxPathSumUtil(root, max_sum);
        
        // Special case: If the root node itself has only one child, the utility function 
        // won't update max_sum because a valid path between TWO leaves must split at some node.
        // We handle this edge case below.
        if (max_sum == INT_MIN) {
            return val;
        }
        
        return max_sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna