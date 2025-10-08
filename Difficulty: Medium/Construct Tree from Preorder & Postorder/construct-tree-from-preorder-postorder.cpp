#include <vector>
#include <unordered_map>

/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
private:
    // Recursive helper function to construct the tree
    Node* buildTreeHelper(std::vector<int>& pre, int preStart, int preEnd,
                          std::vector<int>& post, int postStart, int postEnd,
                          std::unordered_map<int, int>& postMap) {
        // Base case 1: Empty subarray
        if (preStart > preEnd) {
            return nullptr;
        }

        // The first element in the preorder subarray is the root
        Node* root = new Node(pre[preStart]);
        
        // Base case 2: If there's only one element, it's a leaf node
        if (preStart == preEnd) {
            return root;
        }
        
        // The next element in preorder is the root of the left subtree
        int leftSubtreeRootVal = pre[preStart + 1];
        
        // Find the index of the left subtree's root in the postorder array
        int postIndexOfLeftRoot = postMap[leftSubtreeRootVal];
        
        // Calculate the number of nodes in the left subtree
        int leftSubtreeSize = postIndexOfLeftRoot - postStart + 1;

        // Recursively build the left subtree
        root->left = buildTreeHelper(pre, preStart + 1, preStart + leftSubtreeSize,
                                     post, postStart, postIndexOfLeftRoot, postMap);

        // Recursively build the right subtree
        root->right = buildTreeHelper(pre, preStart + leftSubtreeSize + 1, preEnd,
                                      post, postIndexOfLeftRoot + 1, postEnd - 1, postMap);

        return root;
    }

public:
    Node *constructTree(std::vector<int> &pre, std::vector<int> &post) {
        int n = pre.size();
        if (n == 0) {
            return nullptr;
        }
        
        // Create a map for quick lookups of postorder indices
        std::unordered_map<int, int> postMap;
        for (int i = 0; i < n; ++i) {
            postMap[post[i]] = i;
        }

        // Start the recursive construction with the full array ranges
        return buildTreeHelper(pre, 0, n - 1, post, 0, n - 1, postMap);
    }
};