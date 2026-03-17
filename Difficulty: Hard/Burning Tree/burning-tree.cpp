#include <queue>
#include <unordered_map>
#include <unordered_set>

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
  public:
    int minTime(Node* root, int target) {
        if (!root) return 0;
        
        std::unordered_map<Node*, Node*> parentMap;
        Node* targetNode = nullptr;
        
        // Step 1: Map parents and find the target node
        std::queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            // If we found the target value, store its node pointer
            if (curr->data == target) {
                targetNode = curr;
            }
            
            // Map left child to current node (parent)
            if (curr->left) {
                parentMap[curr->left] = curr;
                q.push(curr->left);
            }
            
            // Map right child to current node (parent)
            if (curr->right) {
                parentMap[curr->right] = curr;
                q.push(curr->right);
            }
        }
        
        // Step 2: BFS to simulate the burning process
        std::unordered_set<Node*> visited;
        std::queue<Node*> burnQueue;
        
        burnQueue.push(targetNode);
        visited.insert(targetNode);
        
        int time = 0;
        
        while (!burnQueue.empty()) {
            int size = burnQueue.size();
            bool burned_any = false;
            
            for (int i = 0; i < size; i++) {
                Node* curr = burnQueue.front();
                burnQueue.pop();
                
                // Spread fire to left child
                if (curr->left && visited.find(curr->left) == visited.end()) {
                    burnQueue.push(curr->left);
                    visited.insert(curr->left);
                    burned_any = true;
                }
                
                // Spread fire to right child
                if (curr->right && visited.find(curr->right) == visited.end()) {
                    burnQueue.push(curr->right);
                    visited.insert(curr->right);
                    burned_any = true;
                }
                
                // Spread fire to parent
                if (parentMap.find(curr) != parentMap.end() && visited.find(parentMap[curr]) == visited.end()) {
                    burnQueue.push(parentMap[curr]);
                    visited.insert(parentMap[curr]);
                    burned_any = true;
                }
            }
            
            // If the fire successfully spread to any new node, 1 second has passed
            if (burned_any) {
                time++;
            }
        }
        
        return time;
    }
};