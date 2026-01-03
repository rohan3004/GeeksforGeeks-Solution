/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    // Helper function to merge two sorted lists via 'bottom' pointers
    Node* mergeLists(Node* a, Node* b) {
        // If one list is empty, return the other
        if (!a) return b;
        if (!b) return a;

        Node* result;

        // Compare the data and pick the smaller node
        if (a->data < b->data) {
            result = a;
            // Recursively merge the rest
            result->bottom = mergeLists(a->bottom, b);
        } else {
            result = b;
            result->bottom = mergeLists(a, b->bottom);
        }

        // We are creating a single vertical list, so next should be NULL
        result->next = NULL;
        
        return result;
    }

    Node *flatten(Node *root) {
        // Base case: If root is null or we reached the last horizontal node
        if (!root || !root->next) {
            return root;
        }

        // 1. Recursively flatten the list on the right
        root->next = flatten(root->next);

        // 2. Merge the current vertical list (root) with the flattened right list (root->next)
        root = mergeLists(root, root->next);

        // 3. Return the new head of the merged list
        return root;
    }
};