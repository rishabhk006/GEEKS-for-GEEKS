#include <vector>

class Solution {
private:
    long long mergeAndCount(std::vector<int>& arr, int left, int mid, int right) {
        int i = left;
        int j = mid + 1;
        long long inv_count = 0;
        std::vector<int> temp;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                inv_count += (mid - i + 1);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }

        while (j <= right) {
            temp.push_back(arr[j]);
            j++;
        }

        for (int k = left; k <= right; k++) {
            arr[k] = temp[k - left];
        }

        return inv_count;
    }

    long long mergeSortAndCount(std::vector<int>& arr, int left, int right) {
        long long inv_count = 0;
        if (left < right) {
            int mid = left + (right - left) / 2;

            inv_count += mergeSortAndCount(arr, left, mid);
            inv_count += mergeSortAndCount(arr, mid + 1, right);
            inv_count += mergeAndCount(arr, left, mid, right);
        }
        return inv_count;
    }

public:
    long long inversionCount(std::vector<int>& arr) {
        return mergeSortAndCount(arr, 0, arr.size() - 1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna