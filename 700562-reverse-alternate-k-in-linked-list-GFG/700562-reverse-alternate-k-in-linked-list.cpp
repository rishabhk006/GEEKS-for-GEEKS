class Solution {
  public:
    Node* kAltReverse(Node* head, int k) {
        if (!head) return NULL;

        Node *cur = head, *prev = NULL, *next = NULL;
        int cnt = 0;

        // Reverse first k nodes
        while (cur && cnt < k) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            cnt++;
        }

        head->next = cur;

        // Skip next k nodes
        cnt = 0;
        Node* temp = cur;
        while (temp && cnt < k - 1) {
            temp = temp->next;
            cnt++;
        }

        if (temp && temp->next)
            temp->next = kAltReverse(temp->next, k);

        return prev;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna