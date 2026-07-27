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
};*/

class Solution {
    int preIdx;
    int postIdx;

    Node* buildTree(vector<int>& pre, vector<int>& preMirror) {
        int n = pre.size();
        // Create the current node from the preorder traversal
        Node* root = new Node(pre[preIdx++]);

        // The reversed preMirror array essentially acts as the postorder traversal.
        // `preMirror[n - 1 - postIdx]` gives us the current postorder element.
        // If the current root's data is NOT equal to the current postorder element,
        // it means that this node is not a leaf and has children.
        if (root->data != preMirror[n - 1 - postIdx]) {
            root->left = buildTree(pre, preMirror);
        }
        
        // Since it's a full binary tree, if it has a left child, it will also have a right child.
        // Once the left child finishes building, we check again to build the right side.
        if (root->data != preMirror[n - 1 - postIdx]) {
            root->right = buildTree(pre, preMirror);
        }
        
        // Subtrees (if any) are completely built, and now we process the current node in postorder
        postIdx++;
        
        return root;
    }

public:
    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
        preIdx = 0;
        postIdx = 0;
        return buildTree(pre, preMirror);
    }
};