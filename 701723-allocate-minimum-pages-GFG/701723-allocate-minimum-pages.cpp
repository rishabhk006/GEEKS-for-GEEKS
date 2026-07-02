#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPossible(const vector<int> &arr, int k, int max_pages) {
        int student_count = 1;
        int current_pages = 0;
        
        for (int pages : arr) {
            if (pages > max_pages) {
                return false;
            }
            if (current_pages + pages > max_pages) {
                student_count++;
                current_pages = pages;
                if (student_count > k) {
                    return false;
                }
            } else {
                current_pages += pages;
            }
        }
        return true;
    }

public:
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (n < k) {
            return -1;
        }
        
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        int res = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(arr, k, mid)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna