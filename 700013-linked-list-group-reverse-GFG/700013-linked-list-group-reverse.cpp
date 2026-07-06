class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        if (!head || k <= 1) {
            return head;
        }

        Node *dummy = new Node(0);
        dummy->next = head;

        Node *before_group = dummy;
        Node *curr = head;

        while (curr) {
            Node *group_start = curr;
            Node *prev = nullptr;
            Node *next_node = nullptr;
            int count = 0;

            while (curr && count < k) {
                next_node = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next_node;
                count++;
            }

            before_group->next = prev;
            group_start->next = curr;
            before_group = group_start;
        }

        Node *new_head = dummy->next;
        delete dummy;
        return new_head;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna