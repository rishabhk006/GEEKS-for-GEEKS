class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // code here
        int n = arr.size();
        stack<int> st;
        int max_area = 0;
        
        for (int i = 0; i <= n; i++) {
            int current_height = (i == n) ? 0 : arr[i];
            
            while (!st.empty() && arr[st.top()] > current_height) {
                int height = arr[st.top()];
                st.pop();
                
                int width = st.empty() ? i : (i - st.top() - 1);
                max_area = max(max_area, height * width);
            }
            st.push(i);
        }
        
        return max_area;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna