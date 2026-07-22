class Solution {
private:
    Node* first = nullptr;
    Node* middle = nullptr;
    Node* last = nullptr;
    Node* prev = nullptr;

    void inOrder(Node* root) {
        if (!root) return;

        inOrder(root->left);

        if (prev != nullptr && root->data < prev->data) {
            if (first == nullptr) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }

        prev = root;

        inOrder(root->right);
    }

public:
    Node* correctBST(Node* root) {
        first = middle = last = prev = nullptr;

        inOrder(root);

        if (first && last) {
            swap(first->data, last->data);
        } else if (first && middle) {
            swap(first->data, middle->data);
        }

        return root; // Returned the modified root
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna