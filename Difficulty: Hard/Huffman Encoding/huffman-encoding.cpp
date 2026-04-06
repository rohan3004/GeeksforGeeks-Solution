#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

// Node structure matching your Python logic
struct Node {
    int data;  // frequency
    int idx;   // smallest original index in subtree
    Node *left, *right;

    // Leaf node constructor
    Node(int d, int i) {
        data = d;
        idx = i;
        left = right = nullptr;
    }

    // Internal node constructor
    Node(Node* l, Node* r) {
        data = l->data + r->data;
        // Important for tie-break: inherit the smallest index
        idx = min(l->idx, r->idx);
        left = l;
        right = r;
    }
};

// Custom comparator matching the Python __lt__ method
struct Compare {
    bool operator()(Node* a, Node* b) {
        if (a->data != b->data) {
            // Smaller frequency has higher priority (top of min-heap)
            return a->data > b->data;
        }
        // If frequencies are equal, smaller index has higher priority
        return a->idx > b->idx;
    }
};

class Solution {
public:
    // Preorder traversal to collect Huffman codes
    void solve(Node* root, string s, vector<string>& ans) {
        if (!root) return;

        // If it's a leaf node, we've found a character's code
        if (!root->left && !root->right) {
            // Special case for single-character strings
            if (s == "") s = "0";
            ans.push_back(s);
            return;
        }

        // Standard Preorder: Visit Left ('0') then Right ('1')
        solve(root->left, s + '0', ans);
        solve(root->right, s + '1', ans);
    }

    vector<string> huffmanCodes(string &S, vector<int> f) {
        int n = S.length();
        priority_queue<Node*, vector<Node*>, Compare> minHeap;

        // Step 1: Push leaf nodes into the min-heap
        for (int i = 0; i < n; i++) {
            minHeap.push(new Node(f[i], i));
        }

        // Step 2: Build the Huffman tree
        while (minHeap.size() > 1) {
            Node* left = minHeap.top();
            minHeap.pop();
            
            Node* right = minHeap.top();
            minHeap.pop();

            // Create an internal node that merges the two smallest
            Node* newNode = new Node(left, right);
            minHeap.push(newNode);
        }

        // Step 3: Traverse the tree starting from the root
        vector<string> ans;
        if (!minHeap.empty()) {
            solve(minHeap.top(), "", ans);
        }
        
        return ans;
    }
};