/* Structure of doubly linked list Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};*/
class Solution {
  public:
    vector<vector<int>> displayList(Node *head) {
        vector<int> forward;
        vector<int> backward;
        
        if (head == nullptr) {
            return {forward, backward};
        }
        
        Node* current = head;
        Node* tail = nullptr;
        
        while (current != nullptr) {
            forward.push_back(current->data);
            tail = current;
            current = current->next;
        }
        
        current = tail;
        while (current != nullptr) {
            backward.push_back(current->data);
            current = current->prev;
        }
        
        return {forward, backward};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna