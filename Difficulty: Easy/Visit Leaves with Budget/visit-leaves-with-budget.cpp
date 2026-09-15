#include <vector>
#include <queue>
#include <algorithm>

/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int getCount(Node *root, int k) {
        if (!root) return 0;

        std::vector<int> leafCosts;
        std::queue<std::pair<Node*, int>> q;

        // The root is at level 1
        q.push({root, 1});

        // Step 1: Traverse the tree to find all leaf nodes
        while (!q.empty()) {
            std::pair<Node*, int> current = q.front();
            q.pop();

            Node* node = current.first;
            int level = current.second;

            // Step 2: If it's a leaf node, record its level (cost)
            if (!node->left && !node->right) {
                leafCosts.push_back(level);
            }

            // Continue traversal
            if (node->left) q.push({node->left, level + 1});
            if (node->right) q.push({node->right, level + 1});
        }

        // Step 3: Sort the leaf costs in ascending order (Greedy choice)
        std::sort(leafCosts.begin(), leafCosts.end());

        int count = 0;

        // Step 4: Visit as many leaves as the budget 'k' allows
        for (int cost : leafCosts) {
            if (k >= cost) {
                k -= cost;
                count++;
            } else {
                // Since the array is sorted, if we can't afford this one, 
                // we can't afford any subsequent ones either.
                break;
            }
        }

        return count;
    }
};