#include <climits>
#include <algorithm>

/* Tree node structure used in the program
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

// Helper structure to pass multiple values up the recursive tree
struct TreeInfo {
    bool isBST;
    int size;
    int minVal;
    int maxVal;
};

class Solution {
private:
    TreeInfo postOrder(Node* root) {
        // Base case: An empty tree is trivially a valid BST of size 0.
        // We set min to INT_MAX and max to INT_MIN so the parent's comparisons always succeed.
        if (root == nullptr) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        // Post-order traversal: visit left and right children first
        TreeInfo left = postOrder(root->left);
        TreeInfo right = postOrder(root->right);

        // Check if the current subtree rooted at 'root' is a valid BST
        if (left.isBST && right.isBST && root->data > left.maxVal && root->data < right.minVal) {
            
            // It is a valid BST. Calculate the new size.
            int currentSize = left.size + right.size + 1;
            
            // The new minimum value is either the root's data (if left is null) or the left's min
            int currentMin = std::min(root->data, left.minVal);
            // The new maximum value is either the root's data (if right is null) or the right's max
            int currentMax = std::max(root->data, right.maxVal);
            
            return {true, currentSize, currentMin, currentMax};
        }

        // If the current tree is NOT a BST, we return false.
        // The size becomes the maximum BST size found so far.
        // minVal and maxVal don't matter anymore, so we can return arbitrary numbers.
        return {false, std::max(left.size, right.size), 0, 0};
    }

public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        return postOrder(root).size;
    }
};