/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
private:
    /**
     * @brief Helper function to perform a reverse in-order traversal.
     * * This function traverses the tree in Right -> Root -> Left order, which
     * visits the nodes in descending order of their values. It updates each
     * node's value with the sum of all values greater than it.
     * * @param node The current node being visited.
     * @param sum A reference to an integer that accumulates the sum of values
     * of the nodes already visited.
     */
    void reverseInorder(Node* node, int &sum) {
        // Base case: If the node is null, we have nothing to do.
        if (!node) {
            return;
        }

        // 1. Recurse on the right subtree first to visit larger nodes.
        reverseInorder(node->right, sum);

        // 2. Process the current node.
        
        // Store the original value of the node.
        int original_val = node->data;
        
        // Update the current node's data with the sum of all greater nodes found so far.
        node->data = sum;
        
        // Add the original value to the sum for subsequent (smaller) nodes.
        sum += original_val;

        // 3. Recurse on the left subtree to visit smaller nodes.
        reverseInorder(node->left, sum);
    }

public:
    /**
     * @brief Transforms a BST into a Greater Sum Tree.
     * * @param root The root of the Binary Search Tree.
     */
    void transformTree(Node *root) {
        // Initialize a variable to keep track of the cumulative sum.
        int sum = 0;
        
        // Start the reverse in-order traversal from the root.
        // `sum` is passed by reference to be updated across recursive calls.
        reverseInorder(root, sum);
    }
};