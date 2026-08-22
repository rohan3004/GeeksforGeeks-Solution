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
}; */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
  private:
    // Helper function to trace the path from root to a target node
    bool findPath(Node* root, int target, string& path) {
        if (!root) return false;
        if (root->data == target) return true;

        // Try left subtree
        path.push_back('L');
        if (findPath(root->left, target, path)) return true;
        path.pop_back(); // Backtrack

        // Try right subtree
        path.push_back('R');
        if (findPath(root->right, target, path)) return true;
        path.pop_back(); // Backtrack

        return false;
    }

  public:
    int numberOfTurns(Node* root, int p, int q) {
        if (!root) return 0;

        string path_p = "";
        string path_q = "";

        // Get structural paths to both nodes
        findPath(root, p, path_p);
        findPath(root, q, path_q);

        // Find the Lowest Common Ancestor (LCA) by skipping the common prefix
        int i = 0;
        while (i < path_p.length() && i < path_q.length() && path_p[i] == path_q[i]) {
            i++;
        }

        // Strip out the shared LCA prefix
        string sp = path_p.substr(i);
        string sq = path_q.substr(i);

        // Construct the full edge sequence from p to q
        // Traveling up from p to LCA requires reversing the remaining edges of p's path
        string full_path = string(sp.rbegin(), sp.rend()) + sq;

        // A direct edge relation (length <= 1) won't have any turns
        if (full_path.length() <= 1) {
            return -1;
        }

        // Count consecutive changes between 'L' and 'R'
        int turns = 0;
        for (int j = 1; j < full_path.length(); ++j) {
            if (full_path[j] != full_path[j-1]) {
                turns++;
            }
        }

        // If there are 0 turns, nodes reside on a straight path
        return turns == 0 ? -1 : turns;
    }
};