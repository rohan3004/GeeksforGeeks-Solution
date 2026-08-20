#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

/* Structure of Binary Tree Node
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
    int solve(Node* root, int &max_diff) {
        // Base case: null node returns a very large value
        if (root == nullptr) {
            return INT_MAX;
        }

        // If it's a leaf node, it has no descendants
        // Just return its data to be used by its ancestors
        if (root->left == nullptr && root->right == nullptr) {
            return root->data;
        }

        // Post-order traversal: get the minimum values from left and right subtrees
        int left_min = solve(root->left, max_diff);
        int right_min = solve(root->right, max_diff);

        // The minimum descendant value for the current node
        int min_descendant = min(left_min, right_min);

        // Update the global maximum difference
        max_diff = max(max_diff, root->data - min_descendant);

        // Return the minimum value among the current node and its descendants
        return min(root->data, min_descendant);
    }

  public:
    int maxDiff(Node* root) {
        int max_diff = INT_MIN; // Initialize with the smallest possible integer
        solve(root, max_diff);
        return max_diff;
    }
};