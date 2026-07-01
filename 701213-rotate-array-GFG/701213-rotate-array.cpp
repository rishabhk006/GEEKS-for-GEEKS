#include <vector>
#include <algorithm>

class Solution {
private:
    void reverse(std::vector<int>& arr, int start, int end) {
        while (start < end) {
            std::swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }

public:
    void rotateArr(std::vector<int>& arr, int d) {
        int n = arr.size();
        if (n == 0) return;
        
        d = d % n; 
        if (d == 0) return;

        reverse(arr, 0, d - 1);
        reverse(arr, d, n - 1);
        reverse(arr, 0, n - 1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna