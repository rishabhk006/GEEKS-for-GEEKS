void build(int node, int l, int r, int arr[], int st[]) {
    if (l == r) {
        st[node] = arr[l];
        return;
    }

    int mid = (l + r) / 2;

    build(node * 2, l, mid, arr, st);
    build(node * 2 + 1, mid + 1, r, arr, st);

    st[node] = min(st[node * 2], st[node * 2 + 1]);
}

int query(int node, int l, int r, int a, int b, int st[]) {
    if (r < a || l > b)
        return INT_MAX;

    if (l >= a && r <= b)
        return st[node];

    int mid = (l + r) / 2;

    int left = query(node * 2, l, mid, a, b, st);
    int right = query(node * 2 + 1, mid + 1, r, a, b, st);

    return min(left, right);
}

int *constructST(int arr[], int n) {
    int *st = new int[4 * n];
    build(1, 0, n - 1, arr, st);
    return st;
}

int RMQ(int st[], int n, int a, int b) {
    return query(1, 0, n - 1, a, b, st);
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna