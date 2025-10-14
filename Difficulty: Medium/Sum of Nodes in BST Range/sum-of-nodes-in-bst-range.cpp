/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    /**
     * @brief Calculates the sum of node values in a BST within a given range.
     * * @param root The root of the Binary Search Tree.
     * @param l The lower bound of the range (inclusive).
     * @param r The upper bound of the range (inclusive).
     * @return The sum of node values within the range [l, r].
     */
    int nodeSum(Node* root, int l, int r) {
        // Base case: if the node is null, there's nothing to add.
        if (root == NULL) {
            return 0;
        }

        // If the current node's value is greater than the upper bound 'r',
        // the sum can only be in the left subtree.
        if (root->data > r) {
            return nodeSum(root->left, l, r);
        }

        // If the current node's value is less than the lower bound 'l',
        // the sum can only be in the right subtree.
        if (root->data < l) {
            return nodeSum(root->right, l, r);
        }

        // If the current node's value is within the range [l, r],
        // the sum is the current node's value plus the sum from both
        // left and right subtrees.
        return root->data + nodeSum(root->left, l, r) + nodeSum(root->right, l, r);
    }
};