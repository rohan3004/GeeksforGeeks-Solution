/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  private:
    // Helper function to reverse a linked list
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr) {
            Node* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }
        return prev;
    }

  public:
    Node *compute(Node *head) {
        // Base case: empty list or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Step 1: Reverse the linked list
        head = reverseList(head);

        // Step 2: Traverse and delete nodes smaller than the max seen so far
        Node* current = head;
        int max_val = head->data;

        while (current != nullptr && current->next != nullptr) {
            if (current->next->data < max_val) {
                // The next node is smaller, so we skip/delete it
                Node* nodeToDelete = current->next;
                current->next = current->next->next;
                
                // Free memory to prevent leaks
                delete nodeToDelete; 
            } else {
                // The next node is greater or equal, keep it and update max_val
                current = current->next;
                max_val = current->data;
            }
        }

        // Step 3: Reverse the list back to its original order
        head = reverseList(head);

        return head;
    }
};