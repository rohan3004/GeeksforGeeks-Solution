#include <vector>
#include <map>

using namespace std;

/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  private:
    // Helper function to perform DFS and calculate sums
    void dfs(Node* root, int hd, map<int, int>& mp) {
        if (root == nullptr) {
            return;
        }
        
        // Traverse the left subtree
        dfs(root->left, hd - 1, mp);
        
        // Add the current node's data to the sum for its horizontal distance
        mp[hd] += root->data;
        
        // Traverse the right subtree
        dfs(root->right, hd + 1, mp);
    }

  public:
    vector<int> verticalSum(Node* root) {
        map<int, int> mp; // Stores horizontal distance as key and sum as value
        vector<int> result;
        
        // Populate the map using DFS
        dfs(root, 0, mp);
        
        // Extract the sums in order from left-most to right-most
        for (auto it : mp) {
            result.push_back(it.second);
        }
        
        return result;
    }
};