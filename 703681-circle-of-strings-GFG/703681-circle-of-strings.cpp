class Solution {
  public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b)
            parent[a] = b;
    }

    int isCircle(vector<string> &arr) {
        parent.resize(26);
        for (int i = 0; i < 26; i++)
            parent[i] = i;

        vector<int> in(26, 0), out(26, 0), used(26, 0);

        for (string &s : arr) {
            int u = s.front() - 'a';
            int v = s.back() - 'a';

            out[u]++;
            in[v]++;
            used[u] = used[v] = 1;

            unite(u, v);
        }

        for (int i = 0; i < 26; i++)
            if (in[i] != out[i])
                return 0;

        int root = -1;

        for (int i = 0; i < 26; i++) {
            if (used[i]) {
                if (root == -1)
                    root = find(i);
                else if (find(i) != root)
                    return 0;
            }
        }

        return 1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna