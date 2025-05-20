class Solution {
  public:
    // Function to map each node to its parent and find the target node.
    Node* mapParents(Node* root, unordered_map<Node*, Node*>& parentMap, int target) {
        queue<Node*> q;
        q.push(root);
        Node* targetNode = nullptr;

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->data == target) {
                targetNode = current;
            }

            if (current->left) {
                parentMap[current->left] = current;
                q.push(current->left);
            }

            if (current->right) {
                parentMap[current->right] = current;
                q.push(current->right);
            }
        }
        return targetNode;
    }

    // Function to perform BFS and calculate time to burn the tree.
    int burnTree(Node* targetNode, unordered_map<Node*, Node*>& parentMap) {
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool didSpread = false;

            for (int i = 0; i < size; i++) {
                Node* current = q.front();
                q.pop();

                // Check left child
                if (current->left && !visited[current->left]) {
                    q.push(current->left);
                    visited[current->left] = true;
                    didSpread = true;
                }

                // Check right child
                if (current->right && !visited[current->right]) {
                    q.push(current->right);
                    visited[current->right] = true;
                    didSpread = true;
                }

                // Check parent
                if (parentMap[current] && !visited[parentMap[current]]) {
                    q.push(parentMap[current]);
                    visited[parentMap[current]] = true;
                    didSpread = true;
                }
            }

            if (didSpread) {
                time++;
            }
        }

        return time;
    }

    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parentMap;
        Node* targetNode = mapParents(root, parentMap, target);
        return burnTree(targetNode, parentMap);
    }
};
