#include <climits>   // For INT_MIN
#include <algorithm> // For std::max

/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
private:
    /**
     * @brief A recursive helper function to find the maximum path sum.
     * @param node The current node in the traversal.
     * @param max_sum A reference to the variable storing the overall maximum path sum.
     * @return The maximum path sum starting at 'node' and extending downwards.
     */
    int solve(Node *node, int &max_sum) {
        // Base case: A null node contributes 0 to the path sum.
        if (node == nullptr) {
            return 0;
        }

        // Recursively find the max path sum in the left and right subtrees.
        // The returned sum from a child might be negative.
        int left_path_sum = solve(node->left, max_sum);
        int right_path_sum = solve(node->right, max_sum);

        // We only consider non-negative path sums from children. If a child's 
        // path sum is negative, we're better off not including it (i.e., treat it as 0).
        int left_contribution = std::max(0, left_path_sum);
        int right_contribution = std::max(0, right_path_sum);

        // This is a candidate for the maximum path sum. It's the path that
        // "peaks" at the current node. It includes the node's value
        // and the best non-negative paths from its left and right children.
        max_sum = std::max(max_sum, node->data + left_contribution + right_contribution);

        // The value returned to the parent must be a "straight" path.
        // It's the current node's value plus the best of the two children's paths.
        // We cannot take both children, as that would create a fork.
        return node->data + std::max(left_contribution, right_contribution);
    }

public:
    int findMaxSum(Node *root) {
        // Initialize the result with the smallest possible integer value.
        // This is important for trees where all node values are negative.
        int max_sum = INT_MIN;

        // Start the recursion from the root. The helper function will traverse
        // the tree and update max_sum with the correct value.
        solve(root, max_sum);

        return max_sum;
    }
};