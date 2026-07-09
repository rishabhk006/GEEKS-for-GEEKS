class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int i = 0, j = 0;
        int platforms = 0, ans = 0;
        int n = arr.size();
        
        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                platforms++;
                ans = max(ans, platforms);
                i++;
            } else {
                platforms--;
                j++;
            }
        }
        
        return ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna