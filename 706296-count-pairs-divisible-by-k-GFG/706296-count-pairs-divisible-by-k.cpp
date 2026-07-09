class Solution {
public:
    long long countKdivPairs(vector<int>& arr, int k) {
        vector<long long> freq(k, 0);
        
        for (int x : arr)
            freq[x % k]++;
        
        long long ans = (freq[0] * (freq[0] - 1)) / 2;
        
        for (int i = 1; i <= (k - 1) / 2; i++)
            ans += freq[i] * freq[k - i];
        
        if (k % 2 == 0)
            ans += (freq[k / 2] * (freq[k / 2] - 1)) / 2;
        
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna