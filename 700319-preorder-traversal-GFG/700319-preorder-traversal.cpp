/*
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution {
  private:
    void solve(Node* root, vector<int>& ans) {
        if (root == NULL) return;
        
        // Root -> Left -> Right
        ans.push_back(root->data);
        solve(root->left, ans);
        solve(root->right, ans);
    }
    
  public:
    // Capital 'O' in preOrder to match Driver.cpp
    vector<int> preOrder(Node* root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna