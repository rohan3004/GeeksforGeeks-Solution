/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // If the list is empty or has only one node, it's already reversed.
        if (head == NULL || head->next == NULL) {
            return head;
        }

        Node *current = head;
        Node *prev_node = NULL; // This will point to the new head at the end.

        while (current != NULL) {
            // Store the next node before we overwrite the pointer.
            Node *next_node = current->next;
            
            // Swap the next and prev pointers for the current node.
            current->next = prev_node;
            current->prev = next_node;
            
            // Move our pointers one position forward for the next iteration.
            prev_node = current;
            current = next_node;
        }
        
        // After the loop, prev_node will be the new head of the reversed list.
        return prev_node;
    }
};