/*
Definition for Node
struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  private:
    // Helper function to check if two trees are exactly identical
    bool isIdentical(Node* n1, Node* n2) {
        // If both nodes are null, the trees are identical up to this point
        if (n1 == nullptr && n2 == nullptr) {
            return true;
        }
        
        // If only one is null, the structure is different
        if (n1 == nullptr || n2 == nullptr) {
            return false;
        }
        
        // Check if the current data matches, and recursively check left and right subtrees
        if (n1->data == n2->data) {
            return isIdentical(n1->left, n2->left) && isIdentical(n1->right, n2->right);
        }
        
        return false;
    }

  public:
    bool isSubTree(Node *root1, Node *root2) {
        // An empty tree is always a subtree
        if (root2 == nullptr) {
            return true;
        }
        
        // If the main tree is empty but the subtree is not, it cannot be a subtree
        if (root1 == nullptr) {
            return false;
        }
        
        // Check if the trees are identical starting from the current root1 node
        if (isIdentical(root1, root2)) {
            return true;
        }
        
        // If not identical, recursively check the left and right children of root1
        return isSubTree(root1->left, root2) || isSubTree(root1->right, root2);
    }
};