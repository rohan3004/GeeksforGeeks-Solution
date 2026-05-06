/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int getSize(Node* root) {
        // Base case: If the node is NULL, it doesn't contribute to the size.
        if (root == NULL) {
            return 0;
        }
        
        // Recursive case: 1 (current node) + size of left subtree + size of right subtree
        return 1 + getSize(root->left) + getSize(root->right);
    }
};