class Solution {
public:
    vector<int> lexicographicallyLargest(vector<int>& arr, int N) {
        int i = 0;

        while (i < N) {
            int j = i;
            while (j + 1 < N && (arr[j] + arr[j + 1]) % 2 == 0)
                j++;

            sort(arr.begin() + i, arr.begin() + j + 1, greater<int>());

            i = j + 1;
        }

        return arr;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna