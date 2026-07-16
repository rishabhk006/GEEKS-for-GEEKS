#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxWater(vector<int>& arr) {
        int n = arr.size();
        if (n <= 2) return 0;

        int left = 0, right = n - 1;
        int left_max = 0, right_max = 0;
        long long total_water = 0;

        while (left <= right) {
            if (arr[left] <= arr[right]) {
                if (arr[left] >= left_max) {
                    left_max = arr[left];
                } else {
                    total_water += left_max - arr[left];
                }
                left++;
            } else {
                if (arr[right] >= right_max) {
                    right_max = arr[right];
                } else {
                    total_water += right_max - arr[right];
                }
                right--;
            }
        }

        return total_water;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna