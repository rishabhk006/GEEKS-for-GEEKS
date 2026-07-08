/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> serialize(Node *root) {
     vector<int> arr;
        if (!root) return arr;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            if (curr) {
                arr.push_back(curr->data);
                q.push(curr->left);
                q.push(curr->right);
            } else {
                arr.push_back(-1);
            }
        }
        return arr;
    }

    Node *deSerialize(vector<int> &arr) {
        if (arr.empty() || arr[0] == -1) return nullptr;
        
        Node* root = new Node(arr[0]);
        queue<Node*> q;
        q.push(root);
        
        int i = 1;
        while (!q.empty() && i < arr.size()) {
            Node* curr = q.front();
            q.pop();
            
            if (arr[i] != -1) {
                curr->left = new Node(arr[i]);
                q.push(curr->left);
            }
            i++;
            
            if (i < arr.size() && arr[i] != -1) {
                curr->right = new Node(arr[i]);
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna