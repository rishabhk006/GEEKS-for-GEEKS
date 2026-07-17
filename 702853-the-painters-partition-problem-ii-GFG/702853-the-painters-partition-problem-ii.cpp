class Solution {
public:
    bool possible(vector<int>& arr, int k, long long limit) {
        int painters = 1;
        long long sum = 0;

        for (int x : arr) {
            if (sum + x <= limit) {
                sum += x;
            } else {
                painters++;
                sum = x;

                if (painters > k)
                    return false;
            }
        }

        return true;
    }

    int minTime(vector<int>& arr, int k) {
        long long low = *max_element(arr.begin(), arr.end());
        long long high = 0;

        for (int x : arr)
            high += x;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (possible(arr, k, mid))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna