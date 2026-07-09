class Solution {
public:
    bool twoSum(vector<int>& arr, int target) {
        unordered_set<int> st;

        for (int num : arr) {
            if (st.count(target - num))
                return true;

            st.insert(num);
        }

        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna