class Solution {
public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;
        int left = 0, right = arr.size() - 1;

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == 0) {
                ans.push_back({arr[left], arr[right]});

                int x = arr[left];
                int y = arr[right];

                while (left < right && arr[left] == x)
                    left++;

                while (left < right && arr[right] == y)
                    right--;
            }
            else if (sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna