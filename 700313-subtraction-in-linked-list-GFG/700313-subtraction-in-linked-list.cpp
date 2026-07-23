#include <iostream>
using namespace std;

/*
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  private:
    // Helper function to reverse a linked list
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Helper function to remove leading zeros
    Node* trimLeadingZeros(Node* head) {
        while (head != NULL && head->data == 0) {
            head = head->next;
        }
        return head;
    }

    // Helper function to calculate length
    int getLength(Node* head) {
        int len = 0;
        while (head != NULL) {
            len++;
            head = head->next;
        }
        return len;
    }

  public:
    Node* subLinkedList(Node* head1, Node* head2) {
        // Step 1: Remove leading zeros
        head1 = trimLeadingZeros(head1);
        head2 = trimLeadingZeros(head2);

        // Handle case where one or both numbers are zero
        if (!head1 && !head2) return new Node(0);
        if (!head1) return head2;
        if (!head2) return head1;

        int len1 = getLength(head1);
        int len2 = getLength(head2);

        // Step 2: Ensure head1 holds the larger number
        if (len1 < len2) {
            swap(head1, head2);
        } else if (len1 == len2) {
            Node* curr1 = head1;
            Node* curr2 = head2;
            while (curr1 && curr2 && curr1->data == curr2->data) {
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
            // If numbers are completely equal, return 0
            if (!curr1) return new Node(0);

            if (curr1->data < curr2->data) {
                swap(head1, head2);
            }
        }

        // Step 3: Reverse both lists to subtract from least significant digit
        head1 = reverse(head1);
        head2 = reverse(head2);

        Node* dummy = new Node(-1);
        Node* tail = dummy;
        int borrow = 0;

        // Step 4: Subtract head2 from head1
        while (head1 != NULL) {
            int d1 = head1->data - borrow;
            int d2 = (head2 != NULL) ? head2->data : 0;

            if (d1 < d2) {
                d1 += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }

            int diff = d1 - d2;
            tail->next = new Node(diff);
            tail = tail->next;

            head1 = head1->next;
            if (head2 != NULL) head2 = head2->next;
        }

        // Step 5: Reverse result and remove any leading zeros
        Node* result = reverse(dummy->next);
        result = trimLeadingZeros(result);

        return (result == NULL) ? new Node(0) : result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna