/* Node is defined as
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
  public:
    Node* segregate(Node* head) {
        // Handle edge cases: empty or single-node list
        if (!head || !head->next) {
            return head;
        }

        // Create dummy nodes to act as heads for the 0, 1, and 2 lists.
        // Using dummy nodes simplifies the logic for adding the first element.
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);

        // Create tail pointers for each list.
        Node* zeroTail = zeroHead;
        Node* oneTail = oneHead;
        Node* twoTail = twoHead;

        Node* current = head;

        // Traverse the original list and partition nodes into three separate lists.
        while (current != nullptr) {
            if (current->data == 0) {
                zeroTail->next = current;
                zeroTail = zeroTail->next;
            } else if (current->data == 1) {
                oneTail->next = current;
                oneTail = oneTail->next;
            } else { // current->data == 2
                twoTail->next = current;
                twoTail = twoTail->next;
            }
            current = current->next;
        }
        
        // Connect the three lists in order: 0s -> 1s -> 2s.
        // If the '1s' list is empty, the '0s' list should point to the '2s' list.
        zeroTail->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
        oneTail->next = twoHead->next;
        
        // Terminate the final merged list.
        twoTail->next = nullptr;

        // The new head is the start of the '0s' list.
        // Our logic ensures zeroHead->next points to the first actual node.
        Node* newHead = zeroHead->next;

        // Clean up the dummy nodes to prevent memory leaks.
        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return newHead;
    }
};