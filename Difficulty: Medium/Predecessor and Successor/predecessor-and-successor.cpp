class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;
        
        // Find Predecessor
        Node* curr = root;
        while (curr != NULL) {
            if (curr->data < key) {
                // Potential predecessor found, store it and move right to find a larger one
                pre = curr;
                curr = curr->right;
            } else {
                // Current node is >= key, move left to find smaller values
                curr = curr->left;
            }
        }
        
        // Find Successor
        curr = root;
        while (curr != NULL) {
            if (curr->data > key) {
                // Potential successor found, store it and move left to find a smaller one
                suc = curr;
                curr = curr->left;
            } else {
                // Current node is <= key, move right to find larger values
                curr = curr->right;
            }
        }
        
        return {pre, suc};
    }
};