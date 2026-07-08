struct HuffmanNode {
    int freq;
    int first_idx;
    HuffmanNode *left, *right;

    HuffmanNode(int f, int idx) : freq(f), first_idx(idx), left(nullptr), right(nullptr) {}
};

struct CompareNodes {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        if (a->freq != b->freq) return a->freq > b->freq;
        return a->first_idx > b->first_idx;
    }
};

class Solution {
    void preorder(HuffmanNode* root, string code, vector<string>& result) {
        if (!root) return;
        if (!root->left && !root->right) {
            result.push_back(code);
            return;
        }
        preorder(root->left, code + "0", result);
        preorder(root->right, code + "1", result);
    }

  public:
    vector<string> huffmanCodes(string &s, vector<int> f) {
        int n = s.length();
        vector<string> result;
        if (n == 0) return result;
        
        // Edge case: single distinct character should have a code of "0"
        if (n == 1) {
            result.push_back("0");
            return result;
        }

        priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> pq;

        for (int i = 0; i < n; i++) {
            pq.push(new HuffmanNode(f[i], i));
        }

        while (pq.size() > 1) {
            HuffmanNode* left = pq.top(); pq.pop();
            HuffmanNode* right = pq.top(); pq.pop();

            HuffmanNode* parent = new HuffmanNode(left->freq + right->freq, min(left->first_idx, right->first_idx));
            parent->left = left;
            parent->right = right;
            pq.push(parent);
        }

        if (!pq.empty()) {
            preorder(pq.top(), "", result);
        }
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna