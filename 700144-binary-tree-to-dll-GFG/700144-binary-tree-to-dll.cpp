/* Structure for tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  private:
    Node* head = NULL;
    Node* prev = NULL;

    void inorder(Node* root) {
        if (!root) return;

        // Traverse left subtree
        inorder(root->left);

        // Process current node
        if (prev == NULL) {
            head = root; // First node visited becomes the DLL head
        } else {
            root->left = prev;
            prev->right = root;
        }
        prev = root; // Move prev to current node

        // Traverse right subtree
        inorder(root->right);
    }

  public:
    Node* treeToDLL(Node* root) {
        head = NULL;
        prev = NULL;
        inorder(root);
        return head;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna