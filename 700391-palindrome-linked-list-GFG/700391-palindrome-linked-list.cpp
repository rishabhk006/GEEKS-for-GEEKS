class Solution {
  public:
    Node* reverse(Node* head) {
        Node* prev = NULL;

        while (head) {
            Node* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    bool isPalindrome(Node *head) {
        if (!head || !head->next)
            return true;

        Node *slow = head, *fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* second = reverse(slow->next);
        Node* first = head;
        Node* temp = second;

        while (temp) {
            if (first->data != temp->data)
                return false;

            first = first->next;
            temp = temp->next;
        }

        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna