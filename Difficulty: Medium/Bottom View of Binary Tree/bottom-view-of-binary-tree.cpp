#include <vector>
#include <map>
#include <queue>

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        // Base case: if the tree is empty, return an empty vector.
        if (root == NULL) {
            return ans;
        }
        
        // Map to store the node's data for each horizontal distance.
        // The key is the horizontal distance, and the value is the node's data.
        map<int, int> mpp;
        
        // Queue for level-order traversal. It stores pairs of {Node*, horizontal_distance}.
        queue<pair<Node*, int>> q;
        
        // Start the traversal from the root, which has a horizontal distance of 0.
        q.push({root, 0});
        
        while (!q.empty()) {
            // Get the node and its horizontal distance from the front of the queue.
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            // Update the map with the current node's data for its horizontal distance.
            // If a node already exists for this HD, it will be overwritten.
            // This ensures that the last seen node at each HD (the bottom-most one) is stored.
            mpp[hd] = frontNode->data;
            
            // If the left child exists, push it to the queue with a decreased horizontal distance.
            if (frontNode->left) {
                q.push({frontNode->left, hd - 1});
            }
            
            // If the right child exists, push it to the queue with an increased horizontal distance.
            if (frontNode->right) {
                q.push({frontNode->right, hd + 1});
            }
        }
        
        // The map now holds the bottom view, sorted by horizontal distance.
        // Transfer the values from the map to the result vector.
        for (auto it : mpp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};