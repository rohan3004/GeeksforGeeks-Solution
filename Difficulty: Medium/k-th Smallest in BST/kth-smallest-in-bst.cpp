class Solution {
  public:
    // Helper function to perform the in-order traversal
    void solve(Node* root, int &k, int &ans) {
        if (root == NULL || ans != -1) {
            return;
        }
        
        // 1. Traverse left
        solve(root->left, k, ans);
        
        // If we found the answer in the left subtree, return
        if (ans != -1) {
            return;
        }
        
        // 2. Process current node
        k--;
        if (k == 0) {
            ans = root->data;
            return;
        }
        
        // 3. Traverse right
        solve(root->right, k, ans);
    }

    // Main function with the correct name 'kthSmallest'
    int kthSmallest(Node *root, int k) {
        int ans = -1; // Initialize answer to -1
        solve(root, k, ans);
        return ans;
    }
};