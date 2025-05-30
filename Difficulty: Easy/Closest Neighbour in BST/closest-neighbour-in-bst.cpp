class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        int best = INT_MIN;  // will hold the largest value ≤ k
        Node* cur = root;
        
        while (cur) {
            if (cur->data == k) {
                // perfect match
                return k;
            }
            else if (cur->data < k) {
                // this node is a valid candidate
                best = max(best, cur->data);
                // but maybe there's something larger ≤ k in the right subtree
                cur = cur->right;
            }
            else {
                // cur->data > k, so anything in its right subtree is too big
                cur = cur->left;
            }
        }
        
        // if we never found any node ≤ k, you can decide what to return;
        // here we'll return -1 in that case
        return (best == INT_MIN ? -1 : best);
    }
};
