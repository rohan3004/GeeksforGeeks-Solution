/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* removekeys(Node* root, int l, int r) {
        // Base case: If the current node is null, return null.
        if (root == nullptr) {
            return nullptr;
        }

        // Case 1: The node's value is too large.
        // This node and its entire right subtree are out of range.
        // The new valid subtree must be found in the left child.
        if (root->data > r) {
            return removekeys(root->left, l, r);
        }

        // Case 2: The node's value is too small.
        // This node and its entire left subtree are out of range.
        // The new valid subtree must be found in the right child.
        if (root->data < l) {
            return removekeys(root->right, l, r);
        }

        // Case 3: The node's value is within the range [l, r].
        // Keep this node, but recursively trim its left and right subtrees.
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);

        return root;
    }
};