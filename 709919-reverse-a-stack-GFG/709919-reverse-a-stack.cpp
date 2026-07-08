class Solution {
private:
    void insertAtBottom(stack<int>& st, int element) {
        if (st.empty()) {
            st.push(element);
            return;
        }

        int topElement = st.top();
        st.pop();
        
        insertAtBottom(st, element);
        
        st.push(topElement);
    }

public:
    void reverseStack(stack<int> &st) {
        if (st.empty()) {
            return;
        }

        int topElement = st.top();
        st.pop();
        
        reverseStack(st);
        
        insertAtBottom(st, topElement);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna