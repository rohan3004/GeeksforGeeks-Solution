class Solution {
public:
    // Helper function to perform the traversal
    void solve(Node* node, vector<int>& result) {
        // Base case: If the current node is null, return.
        if (node == NULL) {
            return;
        }
        
        // 1. Recursively traverse the left subtree
        solve(node->left, result);
        
        // 2. Recursively traverse the right subtree
        solve(node->right, result);
        
        // 3. Visit the root node (add its data to the result)
        result.push_back(node->data);
    }

    vector<int> postOrder(Node* root) {
        vector<int> result;
        solve(root, result);
        return result;
    }
};