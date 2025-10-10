#include <vector>
#include <queue>
#include <deque>

/*
class Node {
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
    //Function to store the zig zag order traversal of tree in a list.
    std::vector<int> zigZagTraversal(Node* root) {
        std::vector<int> result;
        if (!root) {
            return result;
        }

        std::queue<Node*> q;
        q.push(root);
        
        // Flag to determine the traversal direction, true for left-to-right
        bool leftToRight = true;

        while (!q.empty()) {
            int levelSize = q.size();
            std::deque<int> currentLevelNodes;

            // Process all nodes of the current level
            for (int i = 0; i < levelSize; i++) {
                Node* currentNode = q.front();
                q.pop();

                // Add the node's value to the deque based on the current direction
                if (leftToRight) {
                    currentLevelNodes.push_back(currentNode->data);
                } else {
                    currentLevelNodes.push_front(currentNode->data);
                }

                // Enqueue children for the next level
                if (currentNode->left) {
                    q.push(currentNode->left);
                }
                if (currentNode->right) {
                    q.push(currentNode->right);
                }
            }

            // Add the correctly ordered nodes from the deque to the final result
            result.insert(result.end(), currentLevelNodes.begin(), currentLevelNodes.end());
            
            // Flip the direction for the next level
            leftToRight = !leftToRight;
        }

        return result;
    }
};