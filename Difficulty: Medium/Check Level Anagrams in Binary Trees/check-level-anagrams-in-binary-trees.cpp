#include <queue>
#include <unordered_map>
using namespace std;

/* Structure of binary tree Node
class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool areAnagrams(Node* root1, Node* root2) {
        // If both are empty, they are trivially anagrams
        if (!root1 && !root2) return true;

        // If only one is empty, they cannot be anagrams
        if (!root1 || !root2) return false;

        queue<Node*> q1, q2;
        q1.push(root1);
        q2.push(root2);

        while (!q1.empty() && !q2.empty()) {
            int n1 = q1.size();
            int n2 = q2.size();

            // If levels have different number of nodes, they aren't anagrams
            if (n1 != n2) return false;

            unordered_map<int, int> freq;

            // Record frequencies of nodes in the current level for the first tree
            for (int i = 0; i < n1; i++) {
                Node* curr = q1.front();
                q1.pop();

                freq[curr->data]++;

                if (curr->left) q1.push(curr->left);
                if (curr->right) q1.push(curr->right);
            }

            // Compare and decrement with nodes in the current level for the second tree
            for (int i = 0; i < n2; i++) {
                Node* curr = q2.front();
                q2.pop();

                // If a value from tree 2 doesn't exist or is exhausted in tree 1
                if (freq.find(curr->data) == freq.end() || freq[curr->data] == 0) {
                    return false;
                }
                freq[curr->data]--;

                if (curr->left) q2.push(curr->left);
                if (curr->right) q2.push(curr->right);
            }
        }

        // Ensure both queues are empty (no extra levels in either tree)
        return q1.empty() && q2.empty();
    }
};