/*
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
  public:
    Node* cloneLinkedList(Node* head) {
        // code here
        if (!head) return NULL;

        Node *cur = head;

        while (cur) {
            Node *copy = new Node(cur->data);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }

        cur = head;
        while (cur) {
            if (cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        Node *dummy = new Node(0);
        Node *tail = dummy;
        cur = head;

        while (cur) {
            Node *copy = cur->next;
            cur->next = copy->next;
            tail->next = copy;
            tail = copy;
            cur = cur->next;
        }

        return dummy->next;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna