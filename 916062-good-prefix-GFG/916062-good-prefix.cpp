#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>

using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> tree;

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] += val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (start <= idx && idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return INT_MAX;
        if (l <= start && end <= r)
            return tree[node];
        int mid = start + (end - start) / 2;
        int p1 = query(2 * node, start, mid, l, r);
        int p2 = query(2 * node + 1, mid + 1, end, l, r);
        return min(p1, p2);
    }

public:
    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
    }

    void addOne(int idx) {
        update(1, 0, n - 1, idx, 1);
    }

    int queryMin(int l, int r) {
        if (l > r) return INT_MAX;
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    int longestPrefix(vector<int>& arr, int k) {
        int n = arr.size();
        if (n == 0) return 0;

        // Step 1: Collect all unique elements and sort them
        vector<int> sorted_unique = arr;
        sort(sorted_unique.begin(), sorted_unique.end());
        sorted_unique.erase(unique(sorted_unique.begin(), sorted_unique.end()), sorted_unique.end());

        int u_size = sorted_unique.size();
        unordered_map<int, int> rank_map;
        for (int i = 0; i < u_size; ++i) {
            rank_map[sorted_unique[i]] = i;
        }

        // Frequencies of each unique element in the current prefix
        vector<int> freq(u_size, 0);
        SegmentTree segTree(u_size);

        for (int i = 0; i < n; ++i) {
            int val = arr[i];
            int r = rank_map[val];

            // Update frequency
            freq[r]++;
            segTree.addOne(r);

            // Find min frequency among all elements x <= val
            int min_freq_smaller = segTree.queryMin(0, r);

            // Check the good prefix condition: F(y) - F(x) <= k
            if (freq[r] - min_freq_smaller > k) {
                return i; // Current prefix fails, return length of previous valid prefix
            }
        }

        return n; // All prefixes are valid
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna