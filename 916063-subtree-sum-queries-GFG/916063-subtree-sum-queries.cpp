#include <vector>

using namespace std;

class Solution {
private:
    int timer = 0;
    vector<int> in, out;
    vector<long long> bit1, bit2;
    vector<bool> isPrime;
    vector<int> nonPrimePrefix;

    void sieve(int n) {
        isPrime.assign(n + 1, true);
        if (n >= 0) isPrime[0] = false;
        if (n >= 1) isPrime[1] = false;
        for (int p = 2; p * p <= n; ++p) {
            if (isPrime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    isPrime[i] = false;
                }
            }
        }
    }

    void dfs(int u, int p, const vector<vector<int>>& adj, const vector<int>& values, vector<int>& nodeAtPos) {
        in[u] = ++timer;
        nodeAtPos[timer] = u;

        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, adj, values, nodeAtPos);
            }
        }
        out[u] = timer;
    }

    // Fenwick Tree (BIT) Helper Functions
    void add(vector<long long>& bit, int idx, long long val, int n) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    void rangeUpdate(int l, int r, long long val, int n) {
        // Point updates on difference array
        add(bit1, l, val, n);
        add(bit1, r + 1, -val, n);
        add(bit2, l, val * (nonPrimePrefix[l - 1]), n);
        add(bit2, r + 1, -val * (nonPrimePrefix[r]), n);
    }

    long long queryPrefix(int idx) {
        long long sum1 = 0, sum2 = 0;
        for (int i = idx; i > 0; i -= i & -i) {
            sum1 += bit1[i];
            sum2 += bit2[i];
        }
        return sum1 * nonPrimePrefix[idx] - sum2;
    }

    long long rangeQuery(int l, int r) {
        return queryPrefix(r) - queryPrefix(l - 1);
    }

public:
    vector<long long> subTreeQuery(int n, vector<vector<int>>& edges, vector<int>& values, int q, vector<vector<int>>& queries) {
        sieve(n);

        vector<vector<int>> adj(n + 1);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        in.resize(n + 1);
        out.resize(n + 1);
        timer = 0;
        vector<int> nodeAtPos(n + 1, 0);

        dfs(1, 0, adj, values, nodeAtPos);

        // Compute prefix sums of non-prime node counts along Euler tour order
        nonPrimePrefix.assign(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int node = nodeAtPos[i];
            nonPrimePrefix[i] = nonPrimePrefix[i - 1] + (!isPrime[node] ? 1 : 0);
        }

        bit1.assign(n + 2, 0);
        bit2.assign(n + 2, 0);

        // Initialize BIT with starting values of non-prime nodes
        for (int i = 1; i <= n; ++i) {
            int node = nodeAtPos[i];
            if (!isPrime[node]) {
                rangeUpdate(i, i, values[node - 1], n);
            }
        }

        vector<long long> ans;

        for (int j = 0; j < q; ++j) {
            int type = queries[j][0];
            int u = queries[j][1];

            if (type == 1) {
                long long x = queries[j][2];
                // Range update in O(log N)
                rangeUpdate(in[u], out[u], x, n);
            } else if (type == 2) {
                // Range query in O(log N)
                long long sum = rangeQuery(in[u], out[u]);
                ans.push_back(sum);
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna