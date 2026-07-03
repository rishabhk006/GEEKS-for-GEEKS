class Solution {
  private:
    DLLNode* getTail(DLLNode* head) {
        while (head != nullptr && head->next != nullptr) {
            head = head->next;
        }
        return head;
    }

    DLLNode* partition(DLLNode* l, DLLNode* h) {
        int x = h->data;
        DLLNode* i = l->prev;

        for (DLLNode* j = l; j != h; j = j->next) {
            if (j->data <= x) {
                i = (i == nullptr) ? l : i->next;
                swap(i->data, j->data);
            }
        }
        i = (i == nullptr) ? l : i->next;
        swap(i->data, h->data);
        return i;
    }

    void quickSortHelper(DLLNode* l, DLLNode* h) {
        if (h != nullptr && l != h && l != h->next) {
            DLLNode* p = partition(l, h);
            quickSortHelper(l, p->prev);
            quickSortHelper(p->next, h);
        }
    }

  public:
    DLLNode* quickSort(DLLNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        DLLNode* tail = getTail(head);
        quickSortHelper(head, tail);
        return head;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna