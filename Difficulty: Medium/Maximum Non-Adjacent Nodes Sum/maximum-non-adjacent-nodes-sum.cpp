#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> // For std::pair

// Definition for a binary tree node.

class Solution {
public:
    /**
     * @brief Calculates the maximum sum of non-adjacent nodes.
     * @param root The root of the binary tree.
     * @return The maximum possible sum.
     */
    int getMaxSum(Node *root) {
        // solve(root) returns a pair {sum_with_root, sum_without_root}
        std::pair<int, int> result = solve(root);
        
        // The final answer is the maximum of the two possibilities for the root node.
        return std::max(result.first, result.second);
    }

private:
    /**
     * @brief A helper function that performs post-order traversal to compute sums.
     * @param node The current node in the traversal.
     * @return A pair where:
     * - first: The maximum sum of the subtree including the node's value.
     * - second: The maximum sum of the subtree excluding the node's value.
     */
    std::pair<int, int> solve(Node* node) {
        // Base case: An empty subtree contributes 0 to both sums.
        if (node == nullptr) {
            return {0, 0};
        }

        // Recursively get the results from the left and right children.
        std::pair<int, int> leftSubtree = solve(node->left);
        std::pair<int, int> rightSubtree = solve(node->right);

        // Case 1: Include the current node.
        // We must exclude its children.
        int sum_with_node = node->data + leftSubtree.second + rightSubtree.second;

        // Case 2: Exclude the current node.
        // We can take the maximum possible sum from each child's subtree.
        int sum_without_node = std::max(leftSubtree.first, leftSubtree.second) + 
                               std::max(rightSubtree.first, rightSubtree.second);

        return {sum_with_node, sum_without_node};
    }
};