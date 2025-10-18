#include <vector>
#include <algorithm>

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
private:
    /**
     * @brief Performs an inorder traversal of the BST and stores node values in a vector.
     * @param node The current node in the traversal.
     * @param sortedNodes A reference to the vector to store the sorted node values.
     */
    void inorderTraversal(Node* node, std::vector<int>& sortedNodes) {
        if (node == nullptr) {
            return;
        }
        
        // 1. Traverse the left subtree
        inorderTraversal(node->left, sortedNodes);
        
        // 2. Visit the root node (add its data to the vector)
        sortedNodes.push_back(node->data);
        
        // 3. Traverse the right subtree
        inorderTraversal(node->right, sortedNodes);
    }

public:
    /**
     * @brief Finds the median of a Binary Search Tree.
     * @param root The root of the BST.
     * @return The median value.
     */
    int findMedian(Node* root) {
        // Step 1: Get the inorder traversal of the BST, which gives a sorted list of nodes.
        std::vector<int> sortedNodes;
        inorderTraversal(root, sortedNodes);
        
        // Step 2: Find the total number of nodes.
        int n = sortedNodes.size();
        
        // Step 3: Calculate the median based on the number of nodes.
        if (n % 2 == 1) {
            // If n is odd, the median is the middle element.
            // For a 1-based list V, it's V((n+1)/2).
            // For a 0-indexed vector, the index is (n+1)/2 - 1, which simplifies to n/2.
            return sortedNodes[n / 2];
        } else {
            // If n is even, the median is the (n/2)th element as per the problem statement.
            // For a 1-based list V, it's V(n/2).
            // For a 0-indexed vector, the index is n/2 - 1.
            return sortedNodes[n / 2 - 1];
        }
    }
};