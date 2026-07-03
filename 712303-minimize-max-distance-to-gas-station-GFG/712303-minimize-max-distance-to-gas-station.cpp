class Solution {
  private:
    bool isValid(double dist, const vector<int>& stations, int K) {
        int stationsAdded = 0;
        for (size_t i = 0; i < stations.size() - 1; i++) {
            double gap = stations[i + 1] - stations[i];
            stationsAdded += (int)(gap / dist);
        }
        return stationsAdded <= K;
    }

  public:
    double minMaxDist(vector<int> &stations, int K) {
        double low = 0.0;
        double high = stations.back() - stations.front();
        double ans = high;

        while (high - low > 1e-6) {
            double mid = low + (high - low) / 2.0;
            if (isValid(mid, stations, K)) {
                ans = mid;
                high = mid;
            } else {
                low = mid;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna