#include <algorithm>
#include <climits>

/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 
*/

class Solution {
private:
    void inorder(Node* root, int& prev, int& min_diff) {
        if (root == nullptr) {
            return;
        }

        // Traverse the left subtree
        inorder(root->left, prev, min_diff);

        // Process the current node
        if (prev != -1) {
            min_diff = std::min(min_diff, root->data - prev);
        }
        prev = root->data;

        // Traverse the right subtree
        inorder(root->right, prev, min_diff);
    }

public:
    int absDiff(Node *root) {
        int min_diff = INT_MAX;
        // Since node.data >= 0 per constraints, -1 is a safe uninitialized value
        int prev = -1; 

        inorder(root, prev, min_diff);

        return min_diff;
    }
};