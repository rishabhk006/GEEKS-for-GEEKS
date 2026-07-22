#include <iostream>
#include <algorithm>

using namespace std;

/* 
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
*/

class Solution {
private:
    // Helper function to find the Lowest Common Ancestor (LCA)
    Node* findLCA(Node* root, int a, int b) {
        if (!root || root->data == a || root->data == b) {
            return root;
        }

        Node* left = findLCA(root->left, a, b);
        Node* right = findLCA(root->right, a, b);

        if (left && right) return root; // 'a' and 'b' are in different subtrees
        return left ? left : right;
    }

    // Helper function to find the distance of a target value from a given node
    int findDistance(Node* root, int target, int dist) {
        if (!root) return -1;
        if (root->data == target) return dist;

        int left = findDistance(root->left, target, dist + 1);
        if (left != -1) return left;

        return findDistance(root->right, target, dist + 1);
    }

public:
    int findDist(Node* root, int a, int b) {
        // Step 1: Find the Lowest Common Ancestor
        Node* lca = findLCA(root, a, b);

        // Step 2: Calculate distances from LCA to node 'a' and node 'b'
        int d1 = findDistance(lca, a, 0);
        int d2 = findDistance(lca, b, 0);

        return d1 + d2;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna