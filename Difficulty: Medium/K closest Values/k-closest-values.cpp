#include <vector>
#include <queue>
#include <cmath>
#include <utility>

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
    /**
     * @brief Finds the k values in the BST that are closest to the target.
     * @param root The root of the Binary Search Tree.
     * @param target The target value.
     * @param k The number of closest values to return.
     * @return A vector containing the k closest values.
     */
    vector<int> getKClosest(Node* root, int target, int k) {
        // A max-heap to keep track of the k closest elements found so far.
        // The pair stores {absolute_difference, value}.
        std::priority_queue<std::pair<int, int>> pq;

        // Use a helper function to perform in-order traversal and fill the heap.
        inorder(root, target, k, pq);

        // Extract the results from the priority queue.
        std::vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        // The order of the returned vector does not matter as per the problem.
        return result;
    }

  private:
    /**
     * @brief Performs an in-order traversal to populate the priority queue.
     * @param node The current node in the traversal.
     * @param target The target value.
     * @param k The number of closest elements to find.
     * @param pq The max-heap to store the k closest elements.
     * The default comparator for pairs ensures that the element
     * "farthest" from the target is at the top, ready to be
     * popped if a better candidate is found.
     */
    void inorder(Node* node, int target, int k, std::priority_queue<std::pair<int, int>>& pq) {
        if (!node) {
            return;
        }

        // Traverse the left subtree
        inorder(node->left, target, k, pq);

        // Process the current node
        pq.push({std::abs(node->data - target), node->data});
        if (pq.size() > k) {
            pq.pop();
        }

        // Traverse the right subtree
        inorder(node->right, target, k, pq);
    }
};