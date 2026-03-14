#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        
        // Base case: if tree is empty
        if (root == nullptr) {
            return ans;
        }

        // Map to store the top view node for each horizontal distance (HD).
        // It sorts automatically based on the keys (HD).
        map<int, int> topNodeMap;
        
        // Queue for BFS traversal storing pairs of {Node, HD}
        queue<pair<Node*, int>> q;
        
        // Start with the root at horizontal distance 0
        q.push({root, 0});

        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            Node* currNode = current.first;
            int hd = current.second;

            // If this horizontal distance is being visited for the first time,
            // it means this is the topmost node for this HD.
            if (topNodeMap.find(hd) == topNodeMap.end()) {
                topNodeMap[hd] = currNode->data;
            }

            // Push the left child with HD - 1
            if (currNode->left != nullptr) {
                q.push({currNode->left, hd - 1});
            }
            
            // Push the right child with HD + 1
            if (currNode->right != nullptr) {
                q.push({currNode->right, hd + 1});
            }
        }

        // Extract the values from the map into our answer vector.
        // Since std::map is ordered by key, it inherently reads from leftmost to rightmost.
        for (auto const& [hd, value] : topNodeMap) {
            ans.push_back(value);
        }

        return ans;
    }
};