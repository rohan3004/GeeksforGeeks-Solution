/* Structure for Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  private:
    // Helper function to calculate sum and update the tree
    int convertToSumTree(Node* node) {
        // Base case: If node is null, its sum is 0
        if (node == nullptr) {
            return 0;
        }
        
        // Recursively compute the sum of left and right subtrees
        int leftSum = convertToSumTree(node->left);
        int rightSum = convertToSumTree(node->right);
        
        // Store the original value of the current node
        int originalValue = node->data;
        
        // Update the current node's value to the sum of its subtrees
        node->data = leftSum + rightSum;
        
        // Return the total sum of the subtree rooted at this node
        // (which is its new updated value + its original value)
        return node->data + originalValue;
    }

  public:
    void toSumTree(Node *root) {
        // Start the recursive transformation from the root
        convertToSumTree(root);
    }
};