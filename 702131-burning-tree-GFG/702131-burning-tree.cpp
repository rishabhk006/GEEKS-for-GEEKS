#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

/* Structure for tree node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  private:
    // Helper function to build parent pointers and find the target node pointer
    Node* createParentMapping(Node* root, int target, unordered_map<Node*, Node*>& parentMap) {
        Node* targetNode = nullptr;
        queue<Node*> q;
        q.push(root);
        parentMap[root] = nullptr;

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->data == target) {
                targetNode = current;
            }

            if (current->left) {
                parentMap[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parentMap[current->right] = current;
                q.push(current->right);
            }
        }
        return targetNode;
    }

  public:
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parentMap;
        Node* targetNode = createParentMapping(root, target, parentMap);

        if (!targetNode) return 0;

        unordered_map<Node*, bool> visited;
        queue<Node*> q;

        q.push(targetNode);
        visited[targetNode] = true;

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool fireSpread = false;

            for (int i = 0; i < size; ++i) {
                Node* current = q.front();
                q.pop();

                // Spread to left child
                if (current->left && !visited[current->left]) {
                    visited[current->left] = true;
                    q.push(current->left);
                    fireSpread = true;
                }

                // Spread to right child
                if (current->right && !visited[current->right]) {
                    visited[current->right] = true;
                    q.push(current->right);
                    fireSpread = true;
                }

                // Spread to parent
                if (parentMap[current] && !visited[parentMap[current]]) {
                    visited[parentMap[current]] = true;
                    q.push(parentMap[current]);
                    fireSpread = true;
                }
            }

            // Increment time only if fire spread to at least one new node
            if (fireSpread) {
                time++;
            }
        }

        return time;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna