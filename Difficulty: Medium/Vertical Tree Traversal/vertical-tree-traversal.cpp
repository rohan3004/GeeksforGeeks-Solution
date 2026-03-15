#include <vector>
#include <queue>
#include <map>

using namespace std;

/*
// Node structure as provided
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
    vector<vector<int>> verticalOrder(Node *root) {
        vector<vector<int>> result;
        
        // Base case: if the tree is empty
        if (root == nullptr) {
            return result;
        }

        // Map to store vectors of nodes at every horizontal distance.
        // The map automatically keeps the keys (horizontal distances) sorted.
        map<int, vector<int>> hdMap;

        // Queue for BFS traversal. Stores pairs of (Node*, horizontal_distance)
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            Node* curr = q.front().first;
            int hd = q.front().second;
            q.pop();

            // Insert the current node's data into the map at its horizontal distance
            hdMap[hd].push_back(curr->data);

            // Process left child: horizontal distance decreases by 1
            if (curr->left != nullptr) {
                q.push({curr->left, hd - 1});
            }

            // Process right child: horizontal distance increases by 1
            if (curr->right != nullptr) {
                q.push({curr->right, hd + 1});
            }
        }

        // Traverse the map and construct the final result vector
        for (auto it = hdMap.begin(); it != hdMap.end(); ++it) {
            result.push_back(it->second);
        }

        return result;
    }
};