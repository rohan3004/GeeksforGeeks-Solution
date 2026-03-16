#include <unordered_map>

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
    int solve(Node* node, long long currentSum, int k, std::unordered_map<long long, int>& prefixSums) {
        if (node == nullptr) {
            return 0;
        }
        
        // Update the running sum
        currentSum += node->data;
        int numPaths = 0;
        
        // If (currentSum - k) exists in the map, it means we found valid paths
        if (prefixSums.find(currentSum - k) != prefixSums.end()) {
            numPaths += prefixSums[currentSum - k];
        }
        
        // Add the current sum to the map for child nodes to use
        prefixSums[currentSum]++;
        
        // Recurse into left and right subtrees
        numPaths += solve(node->left, currentSum, k, prefixSums);
        numPaths += solve(node->right, currentSum, k, prefixSums);
        
        // Backtrack: remove the current sum from the map as we go back up the tree
        // This ensures parallel branches don't use each other's prefix sums
        prefixSums[currentSum]--;
        
        return numPaths;
    }
    
  public:
    int countAllPaths(Node *root, int k) {
        std::unordered_map<long long, int> prefixSums;
        
        // Base case: A sum of 0 has occurred exactly once (representing an empty path)
        // This handles cases where a path starting from the root itself exactly equals k
        prefixSums[0] = 1; 
        
        return solve(root, 0, k, prefixSums);
    }
};